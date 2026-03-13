local api = vim.api
local dir, my = vim.g.workspace, vim.fn.expand('%:p')

local float_opt = {
  width = 0.25,
  height = 0.9,
  title = ' dp ',
  relative = 'editor',
  row = 't',
  col = 'r',
}

local command = string.format('%s/.nvim/command/dp.sh %s %s', dir, dir, my)
local win = dofile('/home/KicamonIce/.config/nvim/lua/internal/window.lua')
local bufnr, winid = win:new_float(float_opt, true, true):bufopt('bufhidden', 'hide'):wininfo()

api.nvim_create_autocmd('WinClosed', {
  buffer = bufnr,
  callback = function()
    if api.nvim_win_is_valid(winid) then
      api.nvim_win_close(winid, true)
    end
    api.nvim_buf_delete(bufnr, { force = true })
  end,
})

vim.cmd.term(command)
