describe "A Masgn node" do
  parse "a = 1, 2, 3" do
    [:lasgn, :a, [:array, [:lit, 1], [:lit, 2], [:lit, 3]]]
  end

  parse "a = *x" do
    [:lasgn, :a, [:splat, [:call, nil, :x, [:arglist]]]]
  end

  parse "a, = []" do
    [:masgn, [:array, [:lasgn, :a]], [:array]]
  end

  parse "a, b = b, a" do
    [:masgn,
     [:array, [:lasgn, :a], [:lasgn, :b]],
     [:array, [:lvar, :b], [:lvar, :a]]]
  end

  parse "a, _, b, _, c, _ = x" do
    [:masgn,
     [:array,
      [:lasgn, :a],
      [:lasgn, :_],
      [:lasgn, :b],
      [:lasgn, :_],
      [:lasgn, :c],
      [:lasgn, :_]],
     [:call, nil, :x, [:arglist]]]
  end

  parse "a.b, a.c = x" do
    [:masgn,
     [:array,
      [:attrasgn, [:call, nil, :a, [:arglist]], :b=, [:arglist]],
      [:attrasgn, [:call, nil, :a, [:arglist]], :c=, [:arglist]]],
     [:call, nil, :x, [:arglist]]]
  end

  parse "a[0], a[1] = 1, 2" do
    [:masgn,
     [:array,
      [:attrasgn, [:call, nil, :a, [:arglist]], :[]=, [:arglist, [:lit, 0]]],
      [:attrasgn, [:call, nil, :a, [:arglist]], :[]=, [:arglist, [:lit, 1]]]],
     [:array, [:lit, 1], [:lit, 2]]]
  end

  parse "* = *1" do
    [:masgn, [:array, [:splat]], [:splat, [:lit, 1]]]
  end

  parse "*a = nil" do
    [:masgn, [:array, [:splat, [:lasgn, :a]]], [:nil]]
  end

  parse "*a = x, y, z" do
    [:masgn,
     [:array, [:splat, [:lasgn, :a]]],
     [:array,
      [:call, nil, :x, [:arglist]],
      [:call, nil, :y, [:arglist]],
      [:call, nil, :z, [:arglist]]]]
  end

  parse "*a = x, y, *z" do
    [:masgn,
     [:array, [:splat, [:lasgn, :a]]],
     [:argscat,
      [:array, [:call, nil, :x, [:arglist]], [:call, nil, :y, [:arglist]]],
      [:call, nil, :z, [:arglist]]]]
  end

  parse "a, *b, c = *x" do
    [:masgn,
     [:array, [:lasgn, :a], [:splat, [:lasgn, :b]]],
     [:lasgn, :c],
     [:splat, [:call, nil, :x, [:arglist]]]]
  end

  parse "a, b, *c = *[]" do
    [:masgn,
     [:array, [:lasgn, :a], [:lasgn, :b], [:splat, [:lasgn, :c]]],
     [:splat, [:array]]]
  end

  parse "(*) = x" do
    [:masgn, [:array, [:splat]], [:call, nil, :x, [:arglist]]]
  end

  parse "(*) = *x" do
    [:masgn, [:array, [:splat]], [:splat, [:call, nil, :x, [:arglist]]]]
  end

  parse "(*a) = (x = 1), *[1]" do
    [:masgn,
     [:array, [:splat, [:lasgn, :a]]],
     [:array, [:lasgn, :x, [:lit, 1]], [:lit, 1]]]
  end

  parse "(*a), *b, c = *x" do
    [:masgn,
     [:array, [:masgn, [:array, [:splat, [:lasgn, :a]]]], [:splat, [:lasgn, :b]]],
     [:lasgn, :c],
     [:splat, [:call, nil, :x, [:arglist]]]]
  end

  parse "(*a, b) = m x" do
    [:masgn,
     [:array, [:splat, [:lasgn, :a]]],
     [:lasgn, :b],
     [:call, nil, :m, [:arglist, [:call, nil, :x, [:arglist]]]]]
  end

  parse "(*a, b), (*c, d) = 1, 2, 3" do
    [:masgn,
     [:array,
      [:masgn, [:array, [:splat, [:lasgn, :a]]], [:lasgn, :b]],
      [:masgn, [:array, [:splat, [:lasgn, :c]]], [:lasgn, :d]]],
     [:array, [:lit, 1], [:lit, 2], [:lit, 3]]]
  end

  parse "(a, b, *c, d), (*e, f, g), (*h) = x.y, *x.z" do
    [:masgn,
     [:array,
      [:masgn,
       [:array, [:lasgn, :a], [:lasgn, :b], [:splat, [:lasgn, :c]]],
       [:lasgn, :d]],
      [:masgn, [:array, [:splat, [:lasgn, :e]]], [:lasgn, :f], [:lasgn, :g]],
      [:masgn, [:array, [:splat, [:lasgn, :h]]]]],
     [:argscat,
      [:array, [:call, [:call, nil, :x, [:arglist]], :y, [:arglist]]],
      [:call, [:call, nil, :x, [:arglist]], :z, [:arglist]]]]
  end

  parse "a, (b, (c, *d), *e) = x[0], *y[0]" do
    [:masgn,
     [:array,
      [:lasgn, :a],
      [:masgn,
       [:array,
        [:lasgn, :b],
        [:masgn, [:array, [:lasgn, :c], [:splat, [:lasgn, :d]]]],
        [:splat, [:lasgn, :e]]]]],
     [:argscat,
      [:array, [:call, [:call, nil, :x, [:arglist]], :[], [:arglist, [:lit, 0]]]],
      [:call, [:call, nil, :y, [:arglist]], :[], [:arglist, [:lit, 0]]]]]
  end

  parse "a, (b, (c, *d, (e, (*f)), g), (h, (i, j), k)) = x.y(q, r)" do
    [:masgn,
     [:array,
      [:lasgn, :a],
      [:masgn,
       [:array,
        [:lasgn, :b],
        [:masgn,
         [:array, [:lasgn, :c], [:splat, [:lasgn, :d]]],
         [:masgn,
          [:array, [:lasgn, :e], [:masgn, [:array, [:splat, [:lasgn, :f]]]]]],
         [:lasgn, :g]],
        [:masgn,
         [:array,
          [:lasgn, :h],
          [:masgn, [:array, [:lasgn, :i], [:lasgn, :j]]],
          [:lasgn, :k]]]]]],
     [:call,
      [:call, nil, :x, [:arglist]],
      :y,
      [:arglist, [:call, nil, :q, [:arglist]], [:call, nil, :r, [:arglist]]]]]
  end
end
