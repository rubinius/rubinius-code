#ifndef MEL_VAR_TABLE_HPP
#define MEL_VAR_TABLE_HPP

// We must use MRI's xfree for ALLOC'd memory.
#ifdef RUBINIUS
#undef xfree
#define xfree free
#endif

namespace MELBOURNE {
typedef VALUE stack_type;

  struct vtable {
    ID *tbl;
    int pos;
    int capa;
    struct vtable *prev;
  };

  struct local_vars {
    struct vtable *args;
    struct vtable *vars;
    struct local_vars *prev;
    stack_type cmdargs;
  };

  int vtable_size(const struct vtable* tbl);
  struct vtable* vtable_alloc(struct vtable *prev);
  void vtable_free(struct vtable* tbl);
  void vtable_free_all(struct vtable* tbl);
  void vtable_add(struct vtable* tbl, ID id);
  bool vtable_included(const struct vtable* tbl, ID id);

  void local_vars_free(struct local_vars* vars);
};

#endif
