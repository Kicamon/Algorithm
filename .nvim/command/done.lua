---@diagnostic disable: need-check-nil
math.randomseed(os.time())

local problem_list = vim.g.workspace .. '/docs/题单.md'
local pattern = '(https://[^%s]+)[^%.]+([^%s]+)[^%d]+([^%s]+)[^%d]+([^%s]+)'
local pl = {}

local function init()
  local file, _ = io.open(problem_list, 'r')
  for line in file:lines() do
    local url, dir, retime, last_time = line:match(pattern)

    if url then
      table.insert(pl, {
        line = line,
        url = url,
        dir = dir,
        retime = retime,
        last_time = last_time,
      })
    else
      table.insert(pl, {
        line = line,
        url = ' ',
        dir = ' ',
        retime = '-1',
        last_time = '-1',
      })
    end
  end
  io.close(file)
end

local function done()
  init()

  local a, b, c, d, e = pl[3].line:match('(|[^|]*)(|[^|]*|)([^|]*)|([^|]*)(.*)')
  pl[3].retime = tostring(tonumber(pl[3].retime) + 1)
  pl[3].last_time = os.date('%Y.%m.%d')
  c = ' ' .. tostring(pl[3].retime) .. (' '):rep(#c - 2 - math.floor(math.log10(pl[3].retime)))
  d = '| ' .. pl[3].last_time .. ' '
  pl[3].line = a .. b .. c .. d .. e

  table.sort(pl, function(x, y)
    if x.retime ~= y.retime then
      return x.retime < y.retime
    end
    return x.last_time < y.last_time
  end)

  local file, _ = io.open(problem_list, 'w')
  for _, v in ipairs(pl) do
    file:write(v.line .. '\n')
  end
  io.close()
end

done()
