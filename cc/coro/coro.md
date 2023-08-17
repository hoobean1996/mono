# C++ 20: Coroutine

- C++ 20 Coroutine is `stackless` coroutine,
- C++ 20 provides keywords: `co_await`, `co_yield`, `co_return`
- C++ 20 recoginizes the coroutines by function return values. C++ coroutine function will return `result`, `result` must has a subtype `promise`

```c++
task<int> = co_await f();
```

## std::coroutine_handle
