describe "An Attrasgn node" do
  parse <<-ruby do
      y = 0
      42.method = y
    ruby

    [:block,
     [:lasgn, :y, [:lit, 0]],
     [:attrasgn, [:lit, 42], :method=, [:arglist, [:lvar, :y]]]]
  end

  parse "a.m = *[1]" do
    [:attrasgn,
     [:call, nil, :a, [:arglist]],
     :m=,
     [:arglist, [:splat, [:array, [:lit, 1]]]]]
  end

  parse "a[*b] = c" do
    [:attrasgn,
     [:call, nil, :a, [:arglist]],
     :[]=,
     [:arglist,
      [:argspush,
       [:splat, [:call, nil, :b, [:arglist]]],
       [:call, nil, :c, [:arglist]]]]]
  end

  parse "a[b, *c] = d" do
    [:attrasgn,
     [:call, nil, :a, [:arglist]],
     :[]=,
     [:arglist,
      [:argspush,
       [:argscat,
        [:array, [:call, nil, :b, [:arglist]]],
        [:call, nil, :c, [:arglist]]],
       [:call, nil, :d, [:arglist]]]]]
  end

  parse "a[b, *c] = *d" do
    [:attrasgn,
     [:call, nil, :a, [:arglist]],
     :[]=,
     [:arglist,
      [:argspush,
       [:argscat,
        [:array, [:call, nil, :b, [:arglist]]],
        [:call, nil, :c, [:arglist]]],
       [:splat, [:call, nil, :d, [:arglist]]]]]]
  end

  parse "a[b, *c] = d, e" do
    [:attrasgn,
     [:call, nil, :a, [:arglist]],
     :[]=,
     [:arglist,
      [:argspush,
       [:argscat,
        [:array, [:call, nil, :b, [:arglist]]],
        [:call, nil, :c, [:arglist]]],
       [:array, [:call, nil, :d, [:arglist]], [:call, nil, :e, [:arglist]]]]]]
  end

  parse "a[42] = 24" do
    [:attrasgn,
     [:call, nil, :a, [:arglist]],
     :[]=,
     [:arglist, [:lit, 42], [:lit, 24]]]
  end

  parse "self[index, 0] = other_string" do
    [:attrasgn,
     nil,
     :[]=,
     [:arglist,
      [:call, nil, :index, [:arglist]],
      [:lit, 0],
      [:call, nil, :other_string, [:arglist]]]]
  end

  parse <<-ruby do
      a = []
      a [42] = 24
    ruby

    [:block,
     [:lasgn, :a, [:array]],
     [:attrasgn, [:lvar, :a], :[]=, [:arglist, [:lit, 42], [:lit, 24]]]]
  end
end
