describe "An Iter node" do
  parse "m { }" do
    [:call, nil, :m, [:arglist, [:iter, [:args], [:nil]]]]
  end

  parse "m do end" do
    [:call, nil, :m, [:arglist, [:iter, [:args], [:nil]]]]
  end

  parse "m { x }" do
    [:call, nil, :m, [:arglist, [:iter, [:args], [:call, nil, :x, [:arglist]]]]]
  end

  parse "m { || }" do
    [:call, nil, :m, [:arglist, [:iter, [:args], [:nil]]]]
  end

  parse "m { |; x| }" do
    [:call, nil, :m, [:arglist, [:iter, [:args], [:nil]]]]
  end

  parse "m { |; x, y| x - y + z }" do
    [:call,
     nil,
     :m,
     [:arglist, [:iter, [:args], [:block, [[:lvar, :x], [:lvar, :y]]]]]]
  end

  parse "m { |a| }" do
    [:call, nil, :m, [:arglist, [:iter, [:args, :a], [:nil]]]]
  end

  parse "m { |a, (b, c)| }" do
    [:call,
     nil,
     :m,
     [:arglist,
      [:iter,
       [:args,
        :a,
        [:masgn, [:array, [:lasgn, :b], [:lasgn, :c]], [:lvar, :"_:1"]]],
       [:nil]]]]
  end

  parse "m { |a; x| }" do
    [:call, nil, :m, [:arglist, [:iter, [:args, :a], [:block, [[:lvar, :x]]]]]]
  end

  parse "m { |a=1| }" do
    [:call,
     nil,
     :m,
     [:arglist, [:iter, [:args, :a, [:block, [:lasgn, :a, [:lit, 1]]]], [:nil]]]]
  end

  parse "m { |a=1, (b, (c, *d), *e)| }" do
    [:call,
     nil,
     :m,
     [:arglist,
      [:iter,
       [:args,
        :a,
        [:masgn,
         [:array,
          [:lasgn, :b],
          [:masgn, [:array, [:lasgn, :c], [:splat, [:lasgn, :d]]]],
          [:splat, [:lasgn, :e]]],
         [:lvar, :"_:1"]],
        [:block, [:lasgn, :a, [:lit, 1]]]],
       [:nil]]]]
  end

  parse "m { |a=1; x| }" do
    [:call,
     nil,
     :m,
     [:arglist,
      [:iter,
       [:args, :a, [:block, [:lasgn, :a, [:lit, 1]]]],
       [:block, [[:lvar, :x]]]]]]
  end

  parse "m { |*| }" do
    [:call, nil, :m, [:arglist, [:iter, [:args, :*], [:nil]]]]
  end

  parse "m { |*; x| }" do
    [:call, nil, :m, [:arglist, [:iter, [:args, :*], [:block, [[:lvar, :x]]]]]]
  end

  parse "m { |*a| }" do
    [:call, nil, :m, [:arglist, [:iter, [:args, :"*a"], [:nil]]]]
  end

  parse "m { |*a; x| }" do
    [:call, nil, :m, [:arglist, [:iter, [:args, :"*a"], [:block, [[:lvar, :x]]]]]]
  end

  parse "m { |a:| }" do
    [:call, nil, :m, [:arglist, [:iter, [:args, :a, [:kwargs, [:a]]], [:nil]]]]
  end

  parse "m { |a:; x| }" do
    [:call,
     nil,
     :m,
     [:arglist, [:iter, [:args, :a, [:kwargs, [:a]]], [:block, [[:lvar, :x]]]]]]
  end

  parse "m { |a: 1| }" do
    [:call,
     nil,
     :m,
     [:arglist,
      [:iter, [:args, :a, [:kwargs, [:a], [[:lasgn, :a, [:lit, 1]]]]], [:nil]]]]
  end

  parse "m { |a: 1; x| }" do
    [:call,
     nil,
     :m,
     [:arglist,
      [:iter,
       [:args, :a, [:kwargs, [:a], [[:lasgn, :a, [:lit, 1]]]]],
       [:block, [[:lvar, :x]]]]]]
  end

  parse "m { |**| }" do
    [:call, nil, :m, [:arglist, [:iter, [:args, :**, [:kwargs, [:**]]], [:nil]]]]
  end

  parse "m { |**; x| }" do
    [:call,
     nil,
     :m,
     [:arglist, [:iter, [:args, :**, [:kwargs, [:**]]], [:block, [[:lvar, :x]]]]]]
  end

  parse "m { |**k| }" do
    [:call,
     nil,
     :m,
     [:arglist, [:iter, [:args, :"**k", [:kwargs, [:"**k"]]], [:nil]]]]
  end

  parse "m { |**k; x| }" do
    [:call,
     nil,
     :m,
     [:arglist,
      [:iter, [:args, :"**k", [:kwargs, [:"**k"]]], [:block, [[:lvar, :x]]]]]]
  end

  parse "m { |&b| }" do
    [:call, nil, :m, [:arglist, [:iter, [:args, :"&b"], [:nil]]]]
  end

  parse "m { |&b; x| }" do
    [:call, nil, :m, [:arglist, [:iter, [:args, :"&b"], [:block, [[:lvar, :x]]]]]]
  end

  parse "m { |a, | }" do
    [:call, nil, :m, [:arglist, [:iter, [:args, :a], [:nil]]]]
  end

  parse "m { |a,; x| }" do
    [:call, nil, :m, [:arglist, [:iter, [:args, :a], [:block, [[:lvar, :x]]]]]]
  end

  parse "m { |a, b| }" do
    [:call, nil, :m, [:arglist, [:iter, [:args, :a, :b], [:nil]]]]
  end

  parse "m { |a, b; x| }" do
    [:call, nil, :m, [:arglist, [:iter, [:args, :a, :b], [:block, [[:lvar, :x]]]]]]
  end

  parse "m { |a, b=1| }" do
    [:call,
     nil,
     :m,
     [:arglist,
      [:iter, [:args, :a, :b, [:block, [:lasgn, :b, [:lit, 1]]]], [:nil]]]]
  end

  parse "m { |a, *| }" do
    [:call, nil, :m, [:arglist, [:iter, [:args, :a, :*], [:nil]]]]
  end

  parse "m { |a, *b| }" do
    [:call, nil, :m, [:arglist, [:iter, [:args, :a, :"*b"], [:nil]]]]
  end

  parse "m { |a, b:| }" do
    [:call, nil, :m, [:arglist, [:iter, [:args, :a, :b, [:kwargs, [:b]]], [:nil]]]]
  end

  parse "m { |a, b: 1| }" do
    [:call,
     nil,
     :m,
     [:arglist,
      [:iter, [:args, :a, :b, [:kwargs, [:b], [[:lasgn, :b, [:lit, 1]]]]], [:nil]]]]
  end

  parse "m { |a, **| }" do
    [:call,
     nil,
     :m,
     [:arglist, [:iter, [:args, :a, :**, [:kwargs, [:**]]], [:nil]]]]
  end

  parse "m { |a, **k| }" do
    [:call,
     nil,
     :m,
     [:arglist, [:iter, [:args, :a, :"**k", [:kwargs, [:"**k"]]], [:nil]]]]
  end

  parse "m { |a, &b| }" do
    [:call, nil, :m, [:arglist, [:iter, [:args, :a, :"&b"], [:nil]]]]
  end

  parse "m { |a=1, b=2| }" do
    [:call,
     nil,
     :m,
     [:arglist,
      [:iter,
       [:args, :a, :b, [:block, [:lasgn, :a, [:lit, 1]], [:lasgn, :b, [:lit, 2]]]],
       [:nil]]]]
  end

  parse "m { |a=1, b| }" do
    [:call,
     nil,
     :m,
     [:arglist,
      [:iter, [:args, :a, :b, [:block, [:lasgn, :a, [:lit, 1]]]], [:nil]]]]
  end

  parse "m { |a=1, *| }" do
    [:call,
     nil,
     :m,
     [:arglist,
      [:iter, [:args, :a, :*, [:block, [:lasgn, :a, [:lit, 1]]]], [:nil]]]]
  end

  parse "m { |a=1, *b| }" do
    [:call,
     nil,
     :m,
     [:arglist,
      [:iter, [:args, :a, :"*b", [:block, [:lasgn, :a, [:lit, 1]]]], [:nil]]]]
  end

  parse "m { |a=1, b:| }" do
    [:call,
     nil,
     :m,
     [:arglist,
      [:iter,
       [:args, :a, :b, [:block, [:lasgn, :a, [:lit, 1]]], [:kwargs, [:b]]],
       [:nil]]]]
  end

  parse "m { |a=1, b: 2| }" do
    [:call,
     nil,
     :m,
     [:arglist,
      [:iter,
       [:args,
        :a,
        :b,
        [:block, [:lasgn, :a, [:lit, 1]]],
        [:kwargs, [:b], [[:lasgn, :b, [:lit, 2]]]]],
       [:nil]]]]
  end

  parse "m { |a=1, **| }" do
    [:call,
     nil,
     :m,
     [:arglist,
      [:iter,
       [:args, :a, :**, [:block, [:lasgn, :a, [:lit, 1]]], [:kwargs, [:**]]],
       [:nil]]]]
  end

  parse "m { |a=1, **k| }" do
    [:call,
     nil,
     :m,
     [:arglist,
      [:iter,
       [:args, :a, :"**k", [:block, [:lasgn, :a, [:lit, 1]]], [:kwargs, [:"**k"]]],
       [:nil]]]]
  end

  parse "m { |a=1, &b| }" do
    [:call,
     nil,
     :m,
     [:arglist,
      [:iter, [:args, :a, :"&b", [:block, [:lasgn, :a, [:lit, 1]]]], [:nil]]]]
  end

  parse "m { |*, a| }" do
    [:call, nil, :m, [:arglist, [:iter, [:args, :*, :a], [:nil]]]]
  end

  parse "m { |*a, b| }" do
    [:call, nil, :m, [:arglist, [:iter, [:args, :"*a", :b], [:nil]]]]
  end

  parse "m { |*, a:| }" do
    [:call, nil, :m, [:arglist, [:iter, [:args, :*, :a, [:kwargs, [:a]]], [:nil]]]]
  end

  parse "m { |*a, b:| }" do
    [:call,
     nil,
     :m,
     [:arglist, [:iter, [:args, :"*a", :b, [:kwargs, [:b]]], [:nil]]]]
  end

  parse "m { |*, a: 1| }" do
    [:call,
     nil,
     :m,
     [:arglist,
      [:iter, [:args, :*, :a, [:kwargs, [:a], [[:lasgn, :a, [:lit, 1]]]]], [:nil]]]]
  end

  parse "m { |*a, b: 1| }" do
    [:call,
     nil,
     :m,
     [:arglist,
      [:iter,
       [:args, :"*a", :b, [:kwargs, [:b], [[:lasgn, :b, [:lit, 1]]]]],
       [:nil]]]]
  end

  parse "m { |*, **| }" do
    [:call,
     nil,
     :m,
     [:arglist, [:iter, [:args, :*, :**, [:kwargs, [:**]]], [:nil]]]]
  end

  parse "m { |*a, **| }" do
    [:call,
     nil,
     :m,
     [:arglist, [:iter, [:args, :"*a", :**, [:kwargs, [:**]]], [:nil]]]]
  end

  parse "m { |*, **k| }" do
    [:call,
     nil,
     :m,
     [:arglist, [:iter, [:args, :*, :"**k", [:kwargs, [:"**k"]]], [:nil]]]]
  end

  parse "m { |*a, **k| }" do
    [:call,
     nil,
     :m,
     [:arglist, [:iter, [:args, :"*a", :"**k", [:kwargs, [:"**k"]]], [:nil]]]]
  end

  parse "m { |*, &b| }" do
    [:call, nil, :m, [:arglist, [:iter, [:args, :*, :"&b"], [:nil]]]]
  end

  parse "m { |*a, &b| }" do
    [:call, nil, :m, [:arglist, [:iter, [:args, :"*a", :"&b"], [:nil]]]]
  end

  parse "m { |a:, b:| }" do
    [:call,
     nil,
     :m,
     [:arglist, [:iter, [:args, :a, :b, [:kwargs, [:a, :b]]], [:nil]]]]
  end

  parse "m { |a:, b: 1| }" do
    [:call,
     nil,
     :m,
     [:arglist,
      [:iter,
       [:args, :a, :b, [:kwargs, [:a, :b], [[:lasgn, :b, [:lit, 1]]]]],
       [:nil]]]]
  end

  parse "m { |a:, **| }" do
    [:call,
     nil,
     :m,
     [:arglist, [:iter, [:args, :a, :**, [:kwargs, [:a, :**]]], [:nil]]]]
  end

  parse "m { |a:, **k| }" do
    [:call,
     nil,
     :m,
     [:arglist, [:iter, [:args, :a, :"**k", [:kwargs, [:a, :"**k"]]], [:nil]]]]
  end

  parse "m { |a:, &b| }" do
    [:call,
     nil,
     :m,
     [:arglist, [:iter, [:args, :a, :"&b", [:kwargs, [:a]]], [:nil]]]]
  end

  parse "m { |a: 1, b:| }" do
    [:call,
     nil,
     :m,
     [:arglist,
      [:iter,
       [:args, :a, :b, [:kwargs, [:a, :b], [[:lasgn, :a, [:lit, 1]]]]],
       [:nil]]]]
  end

  parse "m { |a: 1, b: 2| }" do
    [:call,
     nil,
     :m,
     [:arglist,
      [:iter,
       [:args,
        :a,
        :b,
        [:kwargs, [:a, :b], [[:lasgn, :a, [:lit, 1]], [:lasgn, :b, [:lit, 2]]]]],
       [:nil]]]]
  end

  parse "m { |a: 1, **| }" do
    [:call,
     nil,
     :m,
     [:arglist,
      [:iter,
       [:args, :a, :**, [:kwargs, [:a, :**], [[:lasgn, :a, [:lit, 1]]]]],
       [:nil]]]]
  end

  parse "m { |a: 1, **k| }" do
    [:call,
     nil,
     :m,
     [:arglist,
      [:iter,
       [:args, :a, :"**k", [:kwargs, [:a, :"**k"], [[:lasgn, :a, [:lit, 1]]]]],
       [:nil]]]]
  end

  parse "m { |a: 1, &b| }" do
    [:call,
     nil,
     :m,
     [:arglist,
      [:iter,
       [:args, :a, :"&b", [:kwargs, [:a], [[:lasgn, :a, [:lit, 1]]]]],
       [:nil]]]]
  end

  parse "m { |**, &b| }" do
    [:call,
     nil,
     :m,
     [:arglist, [:iter, [:args, :**, :"&b", [:kwargs, [:**]]], [:nil]]]]
  end

  parse "m { |**k, &b| }" do
    [:call,
     nil,
     :m,
     [:arglist, [:iter, [:args, :"**k", :"&b", [:kwargs, [:"**k"]]], [:nil]]]]
  end

  parse "m { n = 1; m { n } }" do
    [:call,
     nil,
     :m,
     [:arglist,
      [:iter,
       [:args],
       [:block,
        [:lasgn, :n, [:lit, 1]],
        [:call, nil, :m, [:arglist, [:iter, [:args], [:lvar, :n]]]]]]]]
  end

  parse "m(x) { |a, b=1, *c, d, e:, f: 2, **k, &l| }" do
    [:call,
     nil,
     :m,
     [:arglist,
      [:call, nil, :x, [:arglist]],
      [:iter,
       [:args,
        :a,
        :b,
        :"*c",
        :d,
        :e,
        :f,
        :"**k",
        :"&l",
        [:block, [:lasgn, :b, [:lit, 1]]],
        [:kwargs, [:e, :f, :"**k"], [[:lasgn, :f, [:lit, 2]]]]],
       [:nil]]]]
  end

  parse "m(x, y) { |a, b=1, *c, d, e:, f: 2, **k, &l| }" do
    [:call,
     nil,
     :m,
     [:arglist,
      [:call, nil, :x, [:arglist]],
      [:call, nil, :y, [:arglist]],
      [:iter,
       [:args,
        :a,
        :b,
        :"*c",
        :d,
        :e,
        :f,
        :"**k",
        :"&l",
        [:block, [:lasgn, :b, [:lit, 1]]],
        [:kwargs, [:e, :f, :"**k"], [[:lasgn, :f, [:lit, 2]]]]],
       [:nil]]]]
  end

  parse "x.m { |a, b=1, *c, d, e:, f: 2, **k, &l| }" do
    [:call,
     [:call, nil, :x, [:arglist]],
     :m,
     [:arglist,
      [:iter,
       [:args,
        :a,
        :b,
        :"*c",
        :d,
        :e,
        :f,
        :"**k",
        :"&l",
        [:block, [:lasgn, :b, [:lit, 1]]],
        [:kwargs, [:e, :f, :"**k"], [[:lasgn, :f, [:lit, 2]]]]],
       [:nil]]]]
  end

  parse "x.m(x, y) { |a, b=1, *c, d, e:, f: 2, **k, &l| }" do
    [:call,
     [:call, nil, :x, [:arglist]],
     :m,
     [:arglist,
      [:call, nil, :x, [:arglist]],
      [:call, nil, :y, [:arglist]],
      [:iter,
       [:args,
        :a,
        :b,
        :"*c",
        :d,
        :e,
        :f,
        :"**k",
        :"&l",
        [:block, [:lasgn, :b, [:lit, 1]]],
        [:kwargs, [:e, :f, :"**k"], [[:lasgn, :f, [:lit, 2]]]]],
       [:nil]]]]
  end

  parse "m { next }" do
    [:call, nil, :m, [:arglist, [:iter, [:args], [:next]]]]
  end

  parse "m { next 1 }" do
    [:call, nil, :m, [:arglist, [:iter, [:args], [:next, [:lit, 1]]]]]
  end

  parse "m { x = 1; next x }" do
    [:call,
     nil,
     :m,
     [:arglist,
      [:iter, [:args], [:block, [:lasgn, :x, [:lit, 1]], [:next, [:lvar, :x]]]]]]
  end

  parse "m { next *x }" do
    [:call,
     nil,
     :m,
     [:arglist, [:iter, [:args], [:next, [:splat, [:call, nil, :x, [:arglist]]]]]]]
  end

  parse "m { break }" do
    [:call, nil, :m, [:arglist, [:iter, [:args], [:break, [:nil]]]]]
  end

  parse "m { break x }" do
    [:call,
     nil,
     :m,
     [:arglist, [:iter, [:args], [:break, [:call, nil, :x, [:arglist]]]]]]
  end

  parse "m { return }" do
    [:call, nil, :m, [:arglist, [:iter, [:args], [:return]]]]
  end

  parse "m { return x }" do
    [:call,
     nil,
     :m,
     [:arglist, [:iter, [:args], [:return, [:call, nil, :x, [:arglist]]]]]]
  end

  parse "m { x = 1; return x }" do
    [:call,
     nil,
     :m,
     [:arglist,
      [:iter, [:args], [:block, [:lasgn, :x, [:lit, 1]], [:return, [:lvar, :x]]]]]]
  end

  parse "m { redo }" do
    [:call, nil, :m, [:arglist, [:iter, [:args], [:redo]]]]
  end

  parse "m { retry }" do
    [:call, nil, :m, [:arglist, [:iter, [:args], [:retry]]]]
  end

  parse "break" do
    [:break, [:nil]]
  end

  parse "redo" do
    [:redo]
  end

  parse "retry" do
    [:retry]
  end

  parse "next" do
    [:next]
  end

  parse "m { super }" do
    [:call, nil, :m, [:arglist, [:iter, [:args], [:zsuper]]]]
  end
end
