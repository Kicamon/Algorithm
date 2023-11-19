" xcpc适用的vim配置
set number
set relativenumber
syntax on
set cursorline
let mapleader = "\<space>"
set showtabline=2
set laststatus=2
colorscheme slate
set tabstop=4
set shiftwidth=4
set softtabstop=4
set autoindent
set smartindent
set list
set listchars=tab:\│\ ,trail:▪
let leadermap=" "
nnoremap W :w<CR>
nnoremap Q :q<CR>
inoremap ( ()<ESC>i
inoremap { {<CR>}<ESC>O
inoremap ' ''<ESC>i
inoremap " ""<ESC>i
inoremap <A-l> <Right>
nnoremap tu :tabe<CR>:edit<space>
nnoremap tn :+tabnext<CR>
nnoremap tp :-tabnext<CR>
vnoremap Y "+y
nnoremap ca ggVG"+y
nnoremap <leader><CR> :noh<CR>
vnoremap N :normal 
nmap <F5> :call Run()<CR>
function! Run()
  execute 'w'
  :set splitright
  :vsplit
  :vertical res -20
  term g++ "%" -std=c++17 -O2 -g -Wall -o "%<" && "./%<" && rm -f "./%<"
endfunction
nmap <leader>cc :call Command()<CR>
function! Command()
  let has_command = getline('.')[0:1]
  if has_command == "//"
    normal! 0veld
  else
    normal! 0i// 
  endif
endfunction
