// RUN: %check_clang_tidy -std=c++11-or-later %s performance-no-automatic-move %t

struct Obj {
  Obj();
  Obj(const Obj &);
  Obj(Obj &&) noexcept;
  virtual ~Obj();
};

template <typename T>
struct StatusOr {
  StatusOr(const T &);
  StatusOr(T &&);
};

struct NonTemplate {
  NonTemplate(const Obj &);
  NonTemplate(Obj &&);
};

template <typename T>
T Make();

StatusOr<Obj> PositiveStatusOrConstValue() {
  const Obj obj = Make<Obj>();
  // [CXX-P2006]: "Constness of `obj` prevents automatic move."
  return obj;
}

NonTemplate PositiveNonTemplateConstValue() {
  const Obj obj = Make<Obj>();
  // [CXX-P2006]: "Constness of `obj` prevents automatic move."
  return obj;
}

Obj PositiveSelfConstValue() {
  const Obj obj = Make<Obj>();
  // [CXX-P2006]: "Constness of `obj` prevents automatic move."
  return obj;
}

// FIXME: Ideally we would warn here too.
NonTemplate PositiveNonTemplateLifetimeExtension() {
  const Obj &obj = Make<Obj>();
  return obj;
}

// FIXME: Ideally we would warn here too.
StatusOr<Obj> PositiveStatusOrLifetimeExtension() {
  const Obj &obj = Make<Obj>();
  return obj;
}

// Negatives.

StatusOr<Obj> Temporary() {
  return Make<const Obj>();
}

StatusOr<Obj> ConstTemporary() {
  return Make<const Obj>();
}

StatusOr<Obj> Nrvo() {
  Obj obj = Make<Obj>();
  return obj;
}

StatusOr<Obj> Ref() {
  Obj &obj = Make<Obj &>();
  return obj;
}

StatusOr<Obj> ConstRef() {
  const Obj &obj = Make<Obj &>();
  return obj;
}

const Obj global;

StatusOr<Obj> Global() {
  return global;
}

struct FromConstRefOnly {
  FromConstRefOnly(const Obj &);
};

FromConstRefOnly FromConstRefOnly() {
  const Obj obj = Make<Obj>();
  return obj;
}
