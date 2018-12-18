
exception not_found
exception error

datatype E = Variable of string | Literal of int | Lambda of string * E
| Lett of ((string * E) list) * E | App of E * E ;

datatype env = Env of (string * E) list                               (*<-----*)
and   result = Value of int | Closure of E * env | Error of int ;

fun extend_env (Env(oldenv), id, value)             =   Env( (id, value):: oldenv);

fun extend_env_all (Env(oldenv), id_value_list) =  Env(id_value_list @ oldenv);
fun  lookup_env (Env(nil), id) = (print("Free Var!! "^id); raise not_found )
	|lookup_env (Env((id1,value1)::b), id) =
					if (id1 = id) then value1
				else lookup_env(Env(b), id) ;


fun interp1(exp,env) =
	case exp of
		Variable(id)   =>  lookup_env(env,id)                                        (*<-----*)
	| Literal(x)   =>  Literal(x)                                         (*<-----*)
	| Lambda(id,exp) => Closure(Lambda(id,exp),env)                                          (*<-----*)
	| App(E1, E2)    => let val V1 = interp1(E1, env)                              (*<-----*)
							val V2 = interp1(E2, env)                              (*<-----*)
						in
							case V1 of
								Closure(Lambda(id,exp),env) =>        (*<-----*)
									let val new_env = extend_env(env,  (*<-----*)
										id, V2)                        (*<-----*)
									in
										interp1(exp, new_env)               (*<-----*)
									end
								| _ => raise error
							end
				| Lett(id_exp_list, E) =>
						let val id_result_list =
							map (fn (id,exp) => (id, interp1(exp,env))) id_exp_list         (*<-----*)
						in
							let val new_env =
									extend_env_all(env, id_result_list) (*<-----*)
								in interp1(E, new_env)                                 (*<-----*)
								end
							end