" xcpc适用的vim配置
set number
set relativenumber
syntax on
set cursorline
let mapleader = "\<space>"
set laststatus=3
colorscheme desert
hi Normal guibg=#282828
hi EndOfBuffer guibg=#282828
hi CursorLine guibg=#3c3836
set tabstop=4
set shiftwidth=4
set softtabstop=4
set autoindent
set smartindent
set list
set listchars=tab:\│∙,trail:∙ "vv Sb
set wildmenu
let &t_SI.="\e[5 q"
let &t_SR.="\e[3 q"
let &t_EI.="\e[1 q"
let leadermap=" "
map H 0
map L $
map J <c-d>
map K <c-u>
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
nnoremap ca :%+y<CR>
nnoremap <leader><CR> :noh<CR>
vnoremap N :normal 
autocmd TerminalOpen term://* startinsert
tnoremap <C-n> <C-\><C-N>
tnoremap <C-o> <C-\><C-N><C-O>
nmap <F5> :call Run()<CR>
function! Run()
	echo " compiling..."
	:! g++ "%" -o "%<" -Wall -std=c++20 && "./%<"
	redraw!
	echohl WarningMsg | echo " Running finish! :-)"
endfunction

