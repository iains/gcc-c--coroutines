//  { dg-additional-options "-std=gnu++20 -fpreprocessed" }

namespace std {
template <typename a, typename> struct coroutine_traits : a {};
template <typename = void> struct coroutine_handle {
  static coroutine_handle from_address(void *);
  operator coroutine_handle<>();
  void *address();
};
struct b {
  int await_ready() noexcept;
  void await_suspend(coroutine_handle<>) noexcept;
  void await_resume() noexcept;
};
} // namespace std
struct c;
struct d {
  c get_return_object();
  std::b initial_suspend();
  std::b final_suspend() noexcept;
  void unhandled_exception();
  std::b yield_value(int);
};
struct e {
  void operator++();
  int operator*();
  int operator!=(e);
};
struct c {
  using promise_type = d;
  e begin();
  e end();
  c f() {
    c g;
    for (auto h : g) {
      auto i = 1;
      co_yield i;
    }
  }
};
