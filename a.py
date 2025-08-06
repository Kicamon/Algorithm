import re
import subprocess

# 读取 markdown 文件
with open("README.md", "r", encoding="utf-8") as f:
    content = f.read()

# 匹配所有 ```c++ ``` 代码块
pattern = re.compile(r"```c\+\+\n(.*?)```", re.DOTALL)
matches = pattern.findall(content)

# 用 clang-format 格式化
formatted_blocks = []
for block in matches:
    result = subprocess.run(
        ["clang-format", "--style=file:.clang-format"],
        input=block.encode(),
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
    )
    formatted_blocks.append(result.stdout.decode())


# 替换原始代码块
def replacer(match):
    return f"```c++\n{formatted_blocks.pop(0)}```"


new_content = pattern.sub(replacer, content)

# 保存结果
with open("README_formatted.md", "w", encoding="utf-8") as f:
    f.write(new_content)
