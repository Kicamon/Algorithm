local probolem_list = vim.g.workspace .. '/docs/题单.md'
local file_path = vim.fn.getcwd() .. '/' .. vim.fn.expand('%')
local path = '..' .. file_path:sub(#vim.g.workspace + 1)
local time = os.date("%Y.%m.%d")
local new_problem = ("|[<++>](<++>)|<++>|%s|%s|0|<++>|"):format(path,time)

local file,_ = io.open(probolem_list, 'a')
 if not file then
  return
end
file:write(new_problem,'\n')
file:close()
