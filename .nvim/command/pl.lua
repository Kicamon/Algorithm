local api, win = vim.api, dofile('/home/KicamonIce/.config/nvim/lua/internal/window.lua')
local probolem_list = vim.g.workspace .. '/docs/题单.md'

local float_opt = {
  width = 0.8,
  height = 0.8,
  title = ' dp ',
  relative = 'editor',
  row = 'c',
  col = 'c',
}

local bufnr, winid = win:new_float(float_opt, true, true):bufopt('bufhidden', 'hide'):wininfo()

vim.cmd.edit(probolem_list)

api.nvim_create_autocmd('WinClosed', {
  buffer = bufnr,
  callback = function()
    if api.nvim_win_is_valid(winid) then
      api.nvim_win_close(winid, true)
    end
    api.nvim_buf_delete(bufnr, { force = true })
  end,
})
