set background=dark
set nu
set ts=4
set sw=4
set cindent
set autoindent
set smartindent

if$LANG[0] == 'k' && $LANG[1] == 'o'
set fileencoding=korea
endif

if has("syntax")
syntax on "Default to no syntax highlighting
endif

set nobackup
set fencs=utf-8,euc-kr,cp949,cp932,euc-jp,shift-jis,big5,latin1,ucs-2le,utf-16

if version < 600
  syntax clear
 elseif exists("b:current_syntax")
   finish
endif

syn case match

syn keyword pbTodo       contained TODO FIXME XXX
syn cluster pbCommentGrp contains=pbTodo

syn keyword pbSyntax     syntax import option
syn keyword pbStructure  package message group
syn keyword pbRepeat     optional required repeated
syn keyword pbDefault    default
syn keyword pbExtend     extend extensions to max
syn keyword pbRPC        service rpc returns

syn keyword pbType      int32 int64 uint32 uint64 sint32 sint64
syn keyword pbType      fixed32 fixed64 sfixed32 sfixed64
syn keyword pbType      float double bool string bytes
syn keyword pbTypedef   enum
syn keyword pbBool      true false

syn match   pbInt     /-\?\<\d\+\>/
syn match   pbInt     /\<0[xX]\x+\>/
syn match   pbFloat   /\<-\?\d*\(\.\d*\)\?/
syn region  pbComment start="\/\*" end="\*\/" contains=@pbCommentGrp
syn region  pbComment start="//" skip="\\$" end="$" keepend contains=@pbCommentGrp
syn region  pbString  start=/"/ skip=/\\./ end=/"/
syn region  pbString  start=/'/ skip=/\\./ end=/'/

if version >= 508 || !exists("did_proto_syn_inits")
  if version < 508
    let did_proto_syn_inits = 1
    command -nargs=+ HiLink hi link <args>
  else
    command -nargs=+ HiLink hi def link <args>
  endif

  HiLink pbTodo         Todo

  HiLink pbSyntax       Include
  HiLink pbStructure    Structure
  HiLink pbRepeat       Repeat
  HiLink pbDefault      Keyword
  HiLink pbExtend       Keyword
  HiLink pbRPC          Keyword
  HiLink pbType         Type
  HiLink pbTypedef      Typedef
  HiLink pbBool         Boolean

  HiLink pbInt          Number
  HiLink pbFloat        Float
  HiLink pbComment      Comment
  HiLink pbString       String

  delcommand HiLink
endif

let b:current_syntax = "proto"

" Indent Python in the Google way.

setlocal indentexpr=GetGooglePythonIndent(v:lnum)

	let s:maxoff = 50 " maximum number of lines to look backwards.

	function GetGooglePythonIndent(lnum)

	  " Indent inside parens.
	    " Align with the open paren unless it is at the end of the line.
		  " E.g.
		    "   open_paren_not_at_EOL(100,
			  "                         (200,
			    "                          300),
				  "                         400)
				    "   open_paren_at_EOL(
					  "       100, 200, 300, 400)
					    call cursor(a:lnum, 1)
	  let [par_line, par_col] = searchpairpos('(\|{\|\[', '', ')\|}\|\]', 'bW',
			          \ "line('.') < " . (a:lnum - s:maxoff) . " ? dummy :"
					          \ . " synIDattr(synID(line('.'), col('.'), 1), 'name')"
							          \ . " =~ '\\(Comment\\|String\\)$'")
	    if par_line > 0
		    call cursor(par_line, 1)
	    if par_col != col("$") - 1
		      return par_col
			      endif
				    endif

					  " Delegate the rest to the original function.
					    return GetPythonIndent(a:lnum)

	endfunction

	let pyindent_nested_paren="&sw*2"
	let pyindent_open_paren="&sw*2"
