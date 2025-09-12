# 获取最近的比赛信息
# 需要的py库：requests beautifulsoup4 pytz dateutil

import requests
from bs4 import BeautifulSoup
import json
import time
from datetime import datetime
import pytz
import re
import html  # 用于处理HTML转义字符
import dateutil.parser  # 用于解析各种日期格式


class ContestCrawler:
    def __init__(self):
        self.headers = {
            "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36",
            "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8",
            "Accept-Language": "zh-CN,zh;q=0.9,en;q=0.8",
            "Connection": "keep-alive",
        }
        self.contests = []
        self.session = requests.Session()
        self.session.headers.update(self.headers)
        self.beijing_tz = pytz.timezone("Asia/Shanghai")  # 北京时区
        self.current_time = datetime.now(self.beijing_tz)  # 当前北京时间

    def fetch_codeforces(self):
        """爬取Codeforces比赛信息"""
        try:
            url = "https://codeforces.com/api/contest.list"
            response = self.session.get(url, timeout=15)
            data = response.json()

            if data["status"] == "OK":
                for contest in data["result"]:
                    if contest["phase"] == "BEFORE":
                        # 转换时间为北京时间
                        start_time = datetime.fromtimestamp(
                            contest["startTimeSeconds"], tz=pytz.utc
                        ).astimezone(self.beijing_tz)
                        duration_hours = contest["durationSeconds"] // 3600
                        duration_minutes = (contest["durationSeconds"] % 3600) // 60

                        self.contests.append(
                            {
                                "platform": "Codeforces",
                                "name": contest["name"],
                                "start_time": start_time,
                                "start_time_str": start_time.strftime("%Y-%m-%d %H:%M"),
                                "duration": f"{duration_hours}:{duration_minutes:02d}",
                                "url": f"https://codeforces.com/contest/{contest['id']}",
                                "sort_key": start_time,
                            }
                        )
                print(
                    f"成功获取 {len([c for c in data['result'] if c['phase'] == 'BEFORE'])} 个Codeforces比赛"
                )
        except Exception as e:
            print(f"获取Codeforces比赛信息失败: {e}")

    def fetch_nowcoder(self):
        """爬取牛客网比赛信息 - 使用直接页面解析"""
        try:
            # 直接访问牛客竞赛页面
            url = "https://ac.nowcoder.com/acm/contest/vip-index"
            response = self.session.get(url, timeout=15)
            soup = BeautifulSoup(response.text, "html.parser")

            # 查找比赛项 - 只获取未开始的比赛
            contest_items = soup.select(".platform-item.js-item:not(.js-end-item)")

            if contest_items:
                for item in contest_items:
                    try:
                        # 提取比赛名称并处理HTML转义字符
                        name_elem = item.select_one(".contest-name")
                        if not name_elem:
                            name_elem = item.select_one(".platform-item-cont h4")
                        name = name_elem.text.strip() if name_elem else "未知比赛"
                        name = html.unescape(name)  # 处理HTML转义字符

                        # 只保留第一个\n之前的内容
                        if "\n" in name:
                            name = name.split("\n")[0].strip()

                        # 检查是否包含转义字符，如果有则进一步处理
                        if "\\" in name:
                            name = name.replace("\\", "")

                        # 提取时间信息
                        time_elem = item.select_one(".contest-time")
                        if not time_elem:
                            time_elem = item.select_one(
                                ".platform-item-cont .match-time-icon"
                            )

                        start_time = None
                        if time_elem:
                            # 尝试从data属性获取ISO格式时间
                            if "data-starttime" in time_elem.attrs:
                                try:
                                    iso_time = time_elem["data-starttime"]
                                    start_time = dateutil.parser.isoparse(iso_time)
                                    # 转换为北京时间
                                    if start_time.tzinfo is None:
                                        start_time = self.beijing_tz.localize(
                                            start_time
                                        )
                                    else:
                                        start_time = start_time.astimezone(
                                            self.beijing_tz
                                        )
                                except Exception as e:
                                    print(f"解析ISO时间失败: {e}")

                            # 如果无法从data属性获取，尝试解析文本
                            if start_time is None:
                                time_text = time_elem.text.strip()
                                # 解析时间字符串
                                time_match = re.search(
                                    r"(\d{4}[-/]\d{1,2}[-/]\d{1,2}[\s\u4e00-\u9fa5]+\d{1,2}:\d{2})",
                                    time_text,
                                )
                                if time_match:
                                    time_str = time_match.group(1)
                                    # 处理中文日期格式
                                    time_str = (
                                        time_str.replace("年", "-")
                                        .replace("月", "-")
                                        .replace("日", "")
                                    )
                                    time_str = re.sub(
                                        r"[\u4e00-\u9fa5]", " ", time_str
                                    ).strip()

                                    try:
                                        start_time = datetime.strptime(
                                            time_str, "%Y-%m-%d %H:%M"
                                        )
                                    except:
                                        start_time = datetime.strptime(
                                            time_str, "%Y-%m-%d %H:%M:%S"
                                        )

                                    # 设置为北京时间
                                    start_time = self.beijing_tz.localize(start_time)

                        # 如果没有解析到时间或时间已过，跳过
                        if start_time is None or start_time <= self.current_time:
                            continue

                        # 提取链接
                        link_elem = item.select_one("a")
                        if link_elem and "href" in link_elem.attrs:
                            href = link_elem["href"]
                            if href.startswith("/"):
                                url = "https://ac.nowcoder.com" + href
                            else:
                                url = href
                        else:
                            url = "https://ac.nowcoder.com/acm/contest/vip-index"

                        # 添加到比赛列表
                        self.contests.append(
                            {
                                "platform": "牛客竞赛",
                                "name": name,
                                "start_time": start_time,
                                "start_time_str": start_time.strftime("%Y-%m-%d %H:%M"),
                                "duration": "2:00",  # 默认值
                                "url": url,
                                "sort_key": start_time,
                            }
                        )
                    except Exception as e:
                        print(f"解析牛客比赛项失败: {e}")
                        continue

                print(f"成功获取 {len(contest_items)} 个牛客比赛")
            else:
                print("未找到牛客比赛项")

        except Exception as e:
            print(f"获取牛客竞赛信息失败: {e}")

    def fetch_luogu(self):
        """爬取洛谷比赛信息 - 改进版本"""
        try:
            # 使用洛谷API获取比赛信息
            api_url = "https://www.luogu.com.cn/contest/list"
            response = self.session.get(api_url, timeout=15)

            # 尝试从页面中提取JSON数据
            pattern = r'JSON\.parse\(decodeURIComponent\("([^"]+)"\)\)'
            match = re.search(pattern, response.text)

            if match:
                try:
                    # 解码URI组件
                    encoded_json = match.group(1)
                    decoded_json = requests.utils.unquote(encoded_json)
                    data = json.loads(decoded_json)

                    # 提取比赛数据
                    contests_data = (
                        data.get("currentData", {})
                        .get("contests", {})
                        .get("result", [])
                    )

                    for contest in contests_data:
                        # 检查比赛是否已结束
                        if contest["endTime"] > time.time():
                            start_time = datetime.fromtimestamp(
                                contest["startTime"], tz=pytz.utc
                            ).astimezone(self.beijing_tz)

                            # 计算持续时间
                            duration_seconds = contest["endTime"] - contest["startTime"]
                            duration_hours = duration_seconds // 3600
                            duration_minutes = (duration_seconds % 3600) // 60

                            self.contests.append(
                                {
                                    "platform": "洛谷",
                                    "name": contest["name"],
                                    "start_time": start_time,
                                    "start_time_str": start_time.strftime(
                                        "%Y-%m-%d %H:%M"
                                    ),
                                    "duration": f"{duration_hours}:{duration_minutes:02d}",
                                    "url": f"https://www.luogu.com.cn/contest/{contest['id']}",
                                    "sort_key": start_time,
                                }
                            )

                    print(f"成功获取 {len(contests_data)} 个洛谷比赛")
                    return
                except Exception as e:
                    print(f"解析洛谷API数据失败: {e}")

            # 如果API方法失败，尝试备用方法：直接解析HTML
            print("尝试备用方法解析洛谷比赛...")
            soup = BeautifulSoup(response.text, "html.parser")

            # 查找包含比赛信息的脚本标签
            script_tags = soup.find_all("script")
            for script in script_tags:
                if script.string and "window._appData" in script.string:
                    try:
                        json_str = script.string.split("window._appData = ")[1].split(
                            ";</script>"
                        )[0]
                        data = json.loads(json_str)

                        contests_data = (
                            data.get("currentData", {})
                            .get("contests", {})
                            .get("result", [])
                        )

                        for contest in contests_data:
                            if contest["endTime"] > time.time():
                                start_time = datetime.fromtimestamp(
                                    contest["startTime"], tz=pytz.utc
                                ).astimezone(self.beijing_tz)

                                duration_seconds = (
                                    contest["endTime"] - contest["startTime"]
                                )
                                duration_hours = duration_seconds // 3600
                                duration_minutes = (duration_seconds % 3600) // 60

                                self.contests.append(
                                    {
                                        "platform": "洛谷",
                                        "name": contest["name"],
                                        "start_time": start_time,
                                        "start_time_str": start_time.strftime(
                                            "%Y-%m-%d %H:%M"
                                        ),
                                        "duration": f"{duration_hours}:{duration_minutes:02d}",
                                        "url": f"https://www.luogu.com.cn/contest/{contest['id']}",
                                        "sort_key": start_time,
                                    }
                                )

                        print(f"通过备用方法获取 {len(contests_data)} 个洛谷比赛")
                        return
                    except Exception as e:
                        print(f"解析备用数据失败: {e}")
                        continue

            # 如果所有方法都失败，尝试最简单的HTML解析
            print("尝试最简单的HTML解析...")
            contest_items = soup.select(".am-panel")
            if not contest_items:
                contest_items = soup.select(".contest-item")

            for item in contest_items:
                try:
                    # 提取比赛名称
                    name_elem = item.select_one("h3, .contest-name")
                    name = name_elem.text.strip() if name_elem else "未知比赛"

                    # 提取时间信息
                    time_elem = item.select_one(".contest-time, .time")
                    if time_elem:
                        time_text = time_elem.text.strip()
                        # 尝试解析时间
                        time_match = re.search(
                            r"(\d{4}[-/]\d{1,2}[-/]\d{1,2}[\s\u4e00-\u9fa5]+\d{1,2}:\d{2})",
                            time_text,
                        )
                        if time_match:
                            time_str = time_match.group(1)
                            time_str = (
                                time_str.replace("年", "-")
                                .replace("月", "-")
                                .replace("日", "")
                            )
                            time_str = re.sub(r"[\u4e00-\u9fa5]", " ", time_str).strip()

                            try:
                                start_time = datetime.strptime(
                                    time_str, "%Y-%m-%d %H:%M"
                                )
                            except:
                                start_time = datetime.strptime(
                                    time_str, "%Y-%m-%d %H:%M:%S"
                                )

                            # 设置为北京时间
                            start_time = self.beijing_tz.localize(start_time)

                            # 只添加未来的比赛
                            if start_time > self.current_time:
                                # 提取链接
                                link_elem = item.select_one("a")
                                url = "https://www.luogu.com.cn/contest/list"
                                if link_elem and "href" in link_elem.attrs:
                                    href = link_elem["href"]
                                    if href.startswith("/"):
                                        url = "https://www.luogu.com.cn" + href
                                    else:
                                        url = href

                                self.contests.append(
                                    {
                                        "platform": "洛谷",
                                        "name": name,
                                        "start_time": start_time,
                                        "start_time_str": start_time.strftime(
                                            "%Y-%m-%d %H:%M"
                                        ),
                                        "duration": "2:00",  # 默认值
                                        "url": url,
                                        "sort_key": start_time,
                                    }
                                )
                except Exception as e:
                    print(f"解析洛谷比赛项失败: {e}")
                    continue

            print(f"通过简单HTML解析获取 {len(contest_items)} 个洛谷比赛")

        except Exception as e:
            print(f"获取洛谷比赛信息失败: {e}")

    def fetch_atcoder(self):
        """爬取AtCoder比赛信息"""
        try:
            url = "https://atcoder.jp/contests/"
            response = self.session.get(url, timeout=15)
            soup = BeautifulSoup(response.text, "html.parser")

            # 查找即将进行的比赛
            upcoming_div = soup.find("div", id="contest-table-upcoming")
            if upcoming_div:
                table = upcoming_div.find("table")
                rows = table.find_all("tr")[1:]  # 跳过表头

                for row in rows:
                    cols = row.find_all("td")
                    if len(cols) >= 3:
                        time_str = cols[0].text.strip()
                        name_tag = cols[1].find("a")
                        duration_str = cols[2].text.strip()

                        # 解析时间（AtCoder使用UTC时间）
                        utc_time = datetime.strptime(time_str, "%Y-%m-%d %H:%M:%S%z")
                        # 转换为北京时间
                        beijing_time = utc_time.astimezone(self.beijing_tz)

                        # 只添加未来的比赛
                        if beijing_time <= self.current_time:
                            continue

                        # 解析持续时间
                        duration_parts = duration_str.split(":")
                        if len(duration_parts) == 2:
                            duration_formatted = (
                                f"{int(duration_parts[0])}:{int(duration_parts[1]):02d}"
                            )
                        else:
                            duration_formatted = duration_str

                        self.contests.append(
                            {
                                "platform": "AtCoder",
                                "name": name_tag.text.strip(),
                                "start_time": beijing_time,
                                "start_time_str": beijing_time.strftime(
                                    "%Y-%m-%d %H:%M"
                                ),
                                "duration": duration_formatted,
                                "url": f"https://atcoder.jp{name_tag['href']}",
                                "sort_key": beijing_time,
                            }
                        )

                print(f"成功获取 {len(rows)} 个AtCoder比赛")
        except Exception as e:
            print(f"获取AtCoder比赛信息失败: {e}")

    def get_all_contests(self):
        """获取所有平台的比赛信息"""
        print("正在获取Codeforces比赛信息...")
        self.fetch_codeforces()

        print("正在获取牛客竞赛信息...")
        self.fetch_nowcoder()

        print("正在获取洛谷比赛信息...")
        self.fetch_luogu()

        print("正在获取AtCoder比赛信息...")
        self.fetch_atcoder()

        # 按开始时间排序
        self.contests.sort(key=lambda x: x["sort_key"])

        return self.contests


def main():
    crawler = ContestCrawler()
    contests = crawler.get_all_contests()

    # 输出结果
    print("\n=== 近期编程竞赛信息 (按时间排序) ===")
    print(f"总共找到 {len(contests)} 个比赛")

    for contest in contests:
        print(f"\n平台: {contest['platform']}")
        print(f"比赛名称: {contest['name']}")
        print(f"开始时间: {contest['start_time_str']} (北京时间)")
        print(f"持续时间: {contest['duration']} 小时")
        print(f"比赛链接: {contest['url']}")
        print("-" * 50)

    # 保存到JSON文件
    with open("recent_contests.json", "w", encoding="utf-8") as f:
        # 转换为可序列化的格式
        serializable_contests = []
        for contest in contests:
            serializable_contest = contest.copy()
            # 将datetime对象转换为字符串
            serializable_contest["start_time"] = serializable_contest[
                "start_time"
            ].isoformat()
            serializable_contest["sort_key"] = serializable_contest[
                "sort_key"
            ].isoformat()
            serializable_contests.append(serializable_contest)

        json.dump(serializable_contests, f, ensure_ascii=False, indent=2)

    print(f"\n已保存 {len(contests)} 个比赛信息到 recent_contests.json")


if __name__ == "__main__":
    main()
