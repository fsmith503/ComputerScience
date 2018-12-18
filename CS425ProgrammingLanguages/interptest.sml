val test1 = AST_APP(AST_IF(AST_BOOL(true), AST_SUCC, AST_PRED), AST_NUM(3)); 

(*
Always 3
*)

 
val test2 = AST_APP(AST_FUN("f", AST_APP(AST_FUN("x", AST_APP(AST_ID("f"), AST_ID("x"))), AST_NUM(5))), AST_FUN("z", AST_ID("x")));
 (*
 If dynamic scope: 5
 If static scope: Error
 *)

 
val test3 = AST_APP(
				AST_FUN("x", 
					AST_APP(
						AST_FUN("f", 
							AST_APP(
								AST_FUN("x", 
									AST_APP(AST_ID("f"), AST_NUM(3))
								)
							, AST_NUM(1)
							)
						)
					,AST_FUN("y", AST_ID("x"))
					)
				), 
			AST_NUM(0));
			
(*
	If dynamic scope: 1
	If static scope: 0

*)
			
val test4 = AST_APP(AST_FUN("y", AST_NUM(0)), 
			AST_APP(AST_FUN("x", AST_APP(AST_ID("x"), AST_ID("x"))),AST_FUN("x", AST_APP(AST_ID("x"), AST_ID("x")))));
			
(*
	If lazy: Returns 0
	If eager: Loops to infinity
*)
			
			
			
val test5 = AST_APP(AST_FUN("z", 
				AST_APP(AST_FUN("x",
						AST_APP(AST_FUN("f",
							AST_APP(AST_FUN("x",
								AST_APP(AST_FUN("z",
									AST_APP(AST_ID("f"), AST_NUM(3))
								), AST_NUM(0))
							),AST_NUM(1))
						),AST_FUN("y", AST_ID("x")))),
					AST_APP(AST_SUCC, AST_ID("z"))
				)),AST_NUM(41));			
								
(*
	If static: 42
	If dynamic: 1
*)								