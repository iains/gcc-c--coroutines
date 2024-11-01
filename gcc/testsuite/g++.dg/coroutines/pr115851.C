// { dg-additional-options "-Wno-pedantic " }
#include <coroutine>

struct SuspendNever {
    bool await_ready() noexcept;
    void await_suspend(std::coroutine_handle<>) noexcept;
    void await_resume() noexcept;
};

struct Coroutine;

struct PromiseType {
    Coroutine get_return_object();
    SuspendNever initial_suspend();
    SuspendNever final_suspend() noexcept;
    void unhandled_exception () {}
};

struct Coroutine {
    using promise_type = PromiseType;
};

struct ErrorOr {
    int release_error();
};

void warnln(int const&);

Coroutine __async_test_input_basic() {
    ({
        co_await SuspendNever{};
	ErrorOr _temporary_result2;
        warnln(_temporary_result2.release_error());
    });
}
