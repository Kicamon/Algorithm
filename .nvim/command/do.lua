math.randomseed(os.time())

local problem_list = vim.g.workspace .. '/docs/题单.md'
local pattern = '(https://[^%s]+)[^%.]+([^%s]+)[^%d]+([^%s]+)[^%d]+([^%s]+)'

local file, _ = io.open(problem_list, 'r')
local pl = {}

---@diagnostic disable-next-line: need-check-nil
for line in file:lines() do
  local url, dir, retime, last_time = line:match(pattern)

  if url then
    table.insert(pl, {
      url = url,
      dir = dir,
      retime = retime,
      last_time = last_time,
    })
  end
end
io.close(file)

table.sort(pl, function(a, b)
  if a.retime ~= b.retime then
    return a.retime < b.retime
  end
  return a.last_time < b.last_time
end)

vim.ui.open(pl[1].url)
