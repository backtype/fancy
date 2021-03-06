require: "compiler"

def Fancy eval: code binding: bnd (nil) file: file ("(fancy-eval)") line: line (1) {
  bnd if_nil: {
    bnd = Binding setup(Rubinius VariableScope of_sender(),
                        Rubinius CompiledMethod of_sender(),
                        Rubinius StaticScope of_sender())
  }

  # The compiled method
  cm = Fancy Compiler compile_code: code vars: (bnd variables()) file: file line: line
  cm scope=(bnd static_scope() dup())
  cm name=('__fancy_eval__)

  script = Rubinius CompiledMethod Script new(cm, file, true)
  script eval_binding=(bnd)
  script eval_source=(code)

  cm scope() script=(script)

  be = Rubinius BlockEnvironment new()
  be under_context(bnd variables(), cm)

  if: (bnd from_proc?()) then: {
    be proc_environment=(bnd proc_environment)
  }

  be from_eval!()

  be call()
}
