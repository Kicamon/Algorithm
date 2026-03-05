local function read_file(name)
  local f = io.open(name, 'r')
  if not f then
    return nil
  end
  local content = f:read('*a')
  f:close()
  return content
end

local dir = '/home/KicamonIce/Documents/Algorithm/'
local gen_cmd = dir .. 'tools/gen.lua'
local std_cmd = './std'
local my_cmd = './my'

-- 设置随机种子
math.randomseed(os.time() + os.clock())

local function compiler()
  os.execute(('g++ %s -std=c++20 -O2 -g -Wall -o std'):format(dir .. 'temp.cc'))
  os.execute(('g++ %s -std=c++20 -O2 -g -Wall -o my'):format(vim.fn.expand('%:p')))
end

compiler()

local test_count = 0
while true do
  test_count = test_count + 1
  io.write(string.format('测试 #%d\n', test_count))
  io.flush()

  -- 生成随机输入数据到 input.txt
  os.execute(gen_cmd .. ' > input.txt')

  -- 运行标准程序
  os.execute(std_cmd .. ' < input.txt > std_output.txt 2> std_err.txt')

  -- 运行待测程序
  os.execute(my_cmd .. ' < input.txt > my_output.txt 2> my_err.txt')

  -- 读取输出
  local std_out = read_file('std_output.txt')
  local my_out = read_file('my_output.txt')

  if std_out ~= my_out then
    print('答案错误！')
    print('\n--- 输入数据 ---')
    print(read_file('input.txt'))
    print('\n--- 标准输出 ---')
    print(std_out)
    print('\n--- 你的输出 ---')
    print(my_out)
    break
  end

  -- 可选：删除临时文件（保留最近一次便于调试）
  os.remove('input.txt')
  os.remove('std_output.txt')
  os.remove('my_output.txt')
end

os.remove('my_err.txt')
os.remove('std_err.txt')
os.remove('my')
os.remove('std')
