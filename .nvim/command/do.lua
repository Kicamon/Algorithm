math.random(os.time())

local problem_list = vim.g.workspace .. '/docs/题单.md'

local file, _ = io.open(problem_list, 'r')
local pl = {}

for line in file:lines() do
  local url = line:match('https://[^% ]+')
  if url then
    table.insert(pl, url)
  end
end

local link = pl[math.random(#pl)]
vim.ui.open(link)
