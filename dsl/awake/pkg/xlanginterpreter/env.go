package xlanginterpreter

type Environment struct {
	store map[string]Object
	outer *Environment
}

func NewEnvironmenet() *Environment {
	return &Environment{
		store: make(map[string]Object),
		outer: nil,
	}
}

func (e *Environment) Get(name string) (Object, bool) {
	obj, ok := e.store[name]
	if !ok && e.outer != nil {
		obj, ok = e.outer.Get(name)
	}
	return obj, ok
}

func (e *Environment) Set(name string, val Object) Object {
	e.store[name] = val
	return val
}

func NewEnclosedEnvironment(outer *Environment) *Environment {
	env := NewEnvironmenet()
	env.outer = outer
	return env
}
