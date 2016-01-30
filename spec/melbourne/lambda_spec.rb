describe "A Lambda node" do
  parse "-> { }" do
    [:lambda, [:args], [:scope, [:nil]]]
  end

  parse "-> { x }" do
    [:lambda, [:args], [:scope, [:call, nil, :x, [:arglist]]]]
  end

  parse "->(a) { }" do
    [:lambda, [:args, :a], [:scope, [:nil]]]
  end

  parse "->(a, b) { }" do
    [:lambda, [:args, :a, :b], [:scope, [:nil]]]
  end

  parse "-> (a, b) { }" do
    [:lambda, [:args, :a, :b], [:scope, [:nil]]]
  end

  parse "-> a, b { x }" do
    [:lambda, [:args, :a, :b], [:scope, [:call, nil, :x, [:arglist]]]]
  end

  parse "-> (a, (b, (c, *d), *e)) { }" do
    [:lambda,
     [:args,
      :a,
      [:masgn,
       [:array,
        [:lasgn, :b],
        [:masgn, [:array, [:lasgn, :c], [:splat, [:lasgn, :d]]]],
        [:splat, [:lasgn, :e]]],
       [:lvar, :"_:1"]]],
     [:scope, [:nil]]]
  end

  parse "-> (a=1) { }" do
    [:lambda, [:args, :a, [:block, [:lasgn, :a, [:lit, 1]]]], [:scope, [:nil]]]
  end

  parse "-> (*) { }" do
    [:lambda, [:args, :*], [:scope, [:nil]]]
  end

  parse "-> (*a) { }" do
    [:lambda, [:args, :"*a"], [:scope, [:nil]]]
  end

  parse "-> (a=1, b) { }" do
    [:lambda, [:args, :a, :b, [:block, [:lasgn, :a, [:lit, 1]]]], [:scope, [:nil]]]
  end

  parse "-> (*, a) { }" do
    [:lambda, [:args, :*, :a], [:scope, [:nil]]]
  end

  parse "-> (*a, b, c:) { }" do
    [:lambda, [:args, :"*a", :b, :c, [:kwargs, [:c]]], [:scope, [:nil]]]
  end

  parse "-> (*a, b, c:, **) { }" do
    [:lambda, [:args, :"*a", :b, :c, :**, [:kwargs, [:c, :**]]], [:scope, [:nil]]]
  end

  parse "-> (a: 1, b:) { }" do
    [:lambda,
     [:args, :a, :b, [:kwargs, [:a, :b], [[:lasgn, :a, [:lit, 1]]]]],
     [:scope, [:nil]]]
  end

  parse "-> (a: 1, b:, &l) { }" do
    [:lambda,
     [:args, :a, :b, :"&l", [:kwargs, [:a, :b], [[:lasgn, :a, [:lit, 1]]]]],
     [:scope, [:nil]]]
  end

  parse "-> (a: 1, b: 2, **k) { }" do
    [:lambda,
     [:args,
      :a,
      :b,
      :"**k",
      [:kwargs,
       [:a, :b, :"**k"],
       [[:lasgn, :a, [:lit, 1]], [:lasgn, :b, [:lit, 2]]]]],
     [:scope, [:nil]]]
  end

  parse "-> a, b=1, *c, d, e:, f: 2, g:, **k, &l { x + a }" do
    [:lambda,
     [:args,
      :a,
      :b,
      :"*c",
      :d,
      :e,
      :f,
      :g,
      :"**k",
      :"&l",
      [:block, [:lasgn, :b, [:lit, 1]]],
      [:kwargs, [:e, :f, :g, :"**k"], [[:lasgn, :f, [:lit, 2]]]]],
     [:scope, [:call, [:call, nil, :x, [:arglist]], :+, [:arglist, [:lvar, :a]]]]]
  end
end
