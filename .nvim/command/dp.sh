dir=$1
myfile=$2

g++ "${dir}/temp.cc" -std=c++20 -O2 -g -Wall -o std
g++ $myfile -std=c++20 -O2 -g -Wall -o my

test_count=0
while true; do
	test_count=$((test_count + 1))
	echo "test #$test_count"

	lua "${dir}/tools/gen.lua" >input.txt
	./std <input.txt >std_output.txt
	./my <input.txt >my_output.txt

	if diff -q std_output.txt my_output.txt >/dev/null; then
		# 输出相同，删除本次临时文件（保留错误输出，因为它们会被下一次覆盖）
		rm -f input.txt std_output.txt my_output.txt
	else
		# 输出不同，打印详细信息并退出循环
		echo "答案错误！"
		echo -e "\n--- 输入数据 ---"
		cat input.txt
		echo -e "\n--- 标准输出 ---"
		cat std_output.txt
		echo -e "\n--- 你的输出 ---"
		cat my_output.txt
		break
	fi
done

rm my std
