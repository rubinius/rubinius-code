describe "A Defn node" do
  parse <<-ruby do
      def m
      end
    ruby

    [:defn, :m, [:args], [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m() end
    ruby

    [:defn, :m, [:args], [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a) end
    ruby

    [:defn, :m, [:args, :a], [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m((a)) end
    ruby

    [:defn,
     :m,
     [:args, [:masgn, [:array, [:lasgn, :a]], [:lvar, :"_:1"]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m((*a, b)) end
    ruby

    [:defn,
     :m,
     [:args,
      [:masgn, [:array, [:splat, [:lasgn, :a]]], [:lasgn, :b], [:lvar, :"_:1"]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a=1) end
    ruby

    [:defn,
      :m,
      [:args, :a, [:block, [:lasgn, :a, [:lit, 1]]]],
      [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(*) end
    ruby

    [:defn, :m, [:args, :*], [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(*a) end
    ruby

    [:defn, :m, [:args, :"*a"], [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a:) end
    ruby

    [:defn, :m, [:args, :a, [:kwargs, [:a]]], [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a: 1) end
    ruby

    [:defn,
     :m,
     [:args, :a, [:kwargs, [:a], [[:lasgn, :a, [:lit, 1]]]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(**) end
    ruby

    [:defn, :m, [:args, :**, [:kwargs, [:**]]], [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(**k) end
    ruby

    [:defn, :m, [:args, :"**k", [:kwargs, [:"**k"]]], [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(&b) end
    ruby

    [:defn, :m, [:args, :"&b"], [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a, b) end
    ruby

    [:defn, :m, [:args, :a, :b], [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a, (b, c)) end
    ruby

    [:defn,
     :m,
     [:args, :a, [:masgn, [:array, [:lasgn, :b], [:lasgn, :c]], [:lvar, :"_:1"]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m((a), (b)) end
    ruby

    [:defn,
     :m,
     [:args,
      [:masgn, [:array, [:lasgn, :a]], [:lvar, :"_:1"]],
      [:masgn, [:array, [:lasgn, :b]], [:lvar, :"_:2"]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m((*), (*)) end
    ruby

    [:defn,
     :m,
     [:args,
      [:masgn, [:array, [:splat]], [:lvar, :"_:1"]],
      [:masgn, [:array, [:splat]], [:lvar, :"_:2"]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m((*a), (*c)) end
    ruby

    [:defn,
     :m,
     [:args,
      [:masgn, [:array, [:splat, [:lasgn, :a]]], [:lvar, :"_:1"]],
      [:masgn, [:array, [:splat, [:lasgn, :c]]], [:lvar, :"_:2"]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m((a, b), (c, d)) end
    ruby

    [:defn,
     :m,
     [:args,
      [:masgn, [:array, [:lasgn, :a], [:lasgn, :b]], [:lvar, :"_:1"]],
      [:masgn, [:array, [:lasgn, :c], [:lasgn, :d]], [:lvar, :"_:2"]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m((a, *b), (*c, d)) end
    ruby

    [:defn,
     :m,
     [:args,
      [:masgn, [:array, [:lasgn, :a], [:splat, [:lasgn, :b]]], [:lvar, :"_:1"]],
      [:masgn, [:array, [:splat, [:lasgn, :c]]], [:lasgn, :d], [:lvar, :"_:2"]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m((a, b, *c, d), (*e, f, g), (*h)) end
    ruby

    [:defn,
     :m,
     [:args,
      [:masgn,
       [:array, [:lasgn, :a], [:lasgn, :b], [:splat, [:lasgn, :c]]],
       [:lasgn, :d],
       [:lvar, :"_:1"]],
      [:masgn,
       [:array, [:splat, [:lasgn, :e]]],
       [:lasgn, :f],
       [:lasgn, :g],
       [:lvar, :"_:2"]],
      [:masgn, [:array, [:splat, [:lasgn, :h]]], [:lvar, :"_:3"]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a, (b, (c, *d), *e)) end
    ruby

    [:defn,
     :m,
     [:args,
      :a,
      [:masgn,
       [:array,
        [:lasgn, :b],
        [:masgn, [:array, [:lasgn, :c], [:splat, [:lasgn, :d]]]],
        [:splat, [:lasgn, :e]]],
       [:lvar, :"_:1"]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a, (b, (c, *d, (e, (*f)), g), (h, (i, j)))) end
    ruby

    [:defn,
     :m,
     [:args,
      :a,
      [:masgn,
       [:array,
        [:lasgn, :b],
        [:masgn,
         [:array, [:lasgn, :c], [:splat, [:lasgn, :d]]],
         [:masgn,
          [:array, [:lasgn, :e], [:masgn, [:array, [:splat, [:lasgn, :f]]]]]],
         [:lasgn, :g]],
        [:masgn,
         [:array, [:lasgn, :h], [:masgn, [:array, [:lasgn, :i], [:lasgn, :j]]]]]],
       [:lvar, :"_:1"]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a, b=1) end
    ruby

    [:defn,
     :m,
     [:args, :a, :b, [:block, [:lasgn, :b, [:lit, 1]]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a, *) end
    ruby

    [:defn, :m, [:args, :a, :*], [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a, *b) end
    ruby

    [:defn, :m, [:args, :a, :"*b"], [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a, b:) end
    ruby

    [:defn, :m, [:args, :a, :b, [:kwargs, [:b]]], [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a, b: 1) end
    ruby

    [:defn,
     :m,
     [:args, :a, :b, [:kwargs, [:b], [[:lasgn, :b, [:lit, 1]]]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a, **) end
    ruby

    [:defn, :m, [:args, :a, :**, [:kwargs, [:**]]], [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a, **k) end
    ruby

    [:defn,
     :m,
     [:args, :a, :"**k", [:kwargs, [:"**k"]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a, &b) end
    ruby

    [:defn, :m, [:args, :a, :"&b"], [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a=1, b) end
    ruby

    [:defn,
     :m,
     [:args, :a, :b, [:block, [:lasgn, :a, [:lit, 1]]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a=1, *) end
    ruby

    [:defn,
     :m,
     [:args, :a, :*, [:block, [:lasgn, :a, [:lit, 1]]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a=1, *b) end
    ruby

    [:defn,
     :m,
     [:args, :a, :"*b", [:block, [:lasgn, :a, [:lit, 1]]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a=1, (b, c)) end
    ruby

    [:defn,
     :m,
     [:args,
      :a,
      [:masgn, [:array, [:lasgn, :b], [:lasgn, :c]], [:lvar, :"_:1"]],
      [:block, [:lasgn, :a, [:lit, 1]]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a=1, (b, (c, *d))) end
    ruby

    [:defn,
     :m,
     [:args,
      :a,
      [:masgn,
       [:array,
        [:lasgn, :b],
        [:masgn, [:array, [:lasgn, :c], [:splat, [:lasgn, :d]]]]],
       [:lvar, :"_:1"]],
      [:block, [:lasgn, :a, [:lit, 1]]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a=1, (b, (c, *d), *e)) end
    ruby

    [:defn,
     :m,
     [:args,
      :a,
      [:masgn,
       [:array,
        [:lasgn, :b],
        [:masgn, [:array, [:lasgn, :c], [:splat, [:lasgn, :d]]]],
        [:splat, [:lasgn, :e]]],
       [:lvar, :"_:1"]],
      [:block, [:lasgn, :a, [:lit, 1]]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a=1, (b), (c)) end
    ruby

    [:defn,
     :m,
     [:args,
      :a,
      [:masgn, [:array, [:lasgn, :b]], [:lvar, :"_:1"]],
      [:masgn, [:array, [:lasgn, :c]], [:lvar, :"_:2"]],
      [:block, [:lasgn, :a, [:lit, 1]]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a=1, (*b), (*c)) end
    ruby

    [:defn,
     :m,
     [:args,
      :a,
      [:masgn, [:array, [:splat, [:lasgn, :b]]], [:lvar, :"_:1"]],
      [:masgn, [:array, [:splat, [:lasgn, :c]]], [:lvar, :"_:2"]],
      [:block, [:lasgn, :a, [:lit, 1]]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a=1, (b, c), (d, e)) end
    ruby

    [:defn,
     :m,
     [:args,
      :a,
      [:masgn, [:array, [:lasgn, :b], [:lasgn, :c]], [:lvar, :"_:1"]],
      [:masgn, [:array, [:lasgn, :d], [:lasgn, :e]], [:lvar, :"_:2"]],
      [:block, [:lasgn, :a, [:lit, 1]]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a=1, (b, *c), (*d, e)) end
    ruby

    [:defn,
     :m,
     [:args,
      :a,
      [:masgn, [:array, [:lasgn, :b], [:splat, [:lasgn, :c]]], [:lvar, :"_:1"]],
      [:masgn, [:array, [:splat, [:lasgn, :d]]], [:lasgn, :e], [:lvar, :"_:2"]],
      [:block, [:lasgn, :a, [:lit, 1]]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a=1, (b, *c), (d, (*e, f))) end
    ruby

    [:defn,
     :m,
     [:args,
      :a,
      [:masgn, [:array, [:lasgn, :b], [:splat, [:lasgn, :c]]], [:lvar, :"_:1"]],
      [:masgn,
       [:array,
        [:lasgn, :d],
        [:masgn, [:array, [:splat, [:lasgn, :e]]], [:lasgn, :f]]],
       [:lvar, :"_:2"]],
      [:block, [:lasgn, :a, [:lit, 1]]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a=1, b:) end
    ruby

    [:defn,
     :m,
     [:args, :a, :b, [:block, [:lasgn, :a, [:lit, 1]]], [:kwargs, [:b]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a=1, b: 2) end
    ruby

    [:defn,
     :m,
     [:args,
      :a,
      :b,
      [:block, [:lasgn, :a, [:lit, 1]]],
      [:kwargs, [:b], [[:lasgn, :b, [:lit, 2]]]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a=1, **) end
    ruby

    [:defn,
     :m,
     [:args, :a, :**, [:block, [:lasgn, :a, [:lit, 1]]], [:kwargs, [:**]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a=1, **k) end
    ruby

    [:defn,
     :m,
     [:args, :a, :"**k", [:block, [:lasgn, :a, [:lit, 1]]], [:kwargs, [:"**k"]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a=1, &b) end
    ruby

    [:defn,
     :m,
     [:args, :a, :"&b", [:block, [:lasgn, :a, [:lit, 1]]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(*, a) end
    ruby

    [:defn, :m, [:args, :*, :a], [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(*a, b) end
    ruby

    [:defn, :m, [:args, :"*a", :b], [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(*, a:) end
    ruby

    [:defn, :m, [:args, :*, :a, [:kwargs, [:a]]], [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(*a, b:) end
    ruby

    [:defn, :m, [:args, :"*a", :b, [:kwargs, [:b]]], [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(*, a: 1) end
    ruby

    [:defn,
     :m,
     [:args, :*, :a, [:kwargs, [:a], [[:lasgn, :a, [:lit, 1]]]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(*a, b: 1) end
    ruby

    [:defn,
     :m,
     [:args, :"*a", :b, [:kwargs, [:b], [[:lasgn, :b, [:lit, 1]]]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(*, **) end
    ruby

    [:defn, :m, [:args, :*, :**, [:kwargs, [:**]]], [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(*a, **) end
    ruby

    [:defn, :m, [:args, :"*a", :**, [:kwargs, [:**]]], [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(*, **k) end
    ruby

    [:defn,
     :m,
     [:args, :*, :"**k", [:kwargs, [:"**k"]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(*a, **k) end
    ruby

    [:defn,
     :m,
     [:args, :"*a", :"**k", [:kwargs, [:"**k"]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(*, &b) end
    ruby

    [:defn, :m, [:args, :*, :"&b"], [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(*a, &b) end
    ruby

    [:defn, :m, [:args, :"*a", :"&b"], [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a:, b:) end
    ruby

    [:defn, :m, [:args, :a, :b, [:kwargs, [:a, :b]]], [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a:, b: 1) end
    ruby

    [:defn,
     :m,
     [:args, :a, :b, [:kwargs, [:a, :b], [[:lasgn, :b, [:lit, 1]]]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a:, **) end
    ruby

    [:defn, :m, [:args, :a, :**, [:kwargs, [:a, :**]]], [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a:, **k) end
    ruby

    [:defn,
     :m,
     [:args, :a, :"**k", [:kwargs, [:a, :"**k"]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a:, &b) end
    ruby

    [:defn, :m, [:args, :a, :"&b", [:kwargs, [:a]]], [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a: 1, b:) end
    ruby

    [:defn,
     :m,
     [:args, :a, :b, [:kwargs, [:a, :b], [[:lasgn, :a, [:lit, 1]]]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a: def m(a: 1) a end, b:) end
    ruby

    [:defn,
     :m,
     [:args,
      :a,
      :b,
      [:kwargs,
       [:a, :b],
       [[:lasgn,
         :a,
         [:defn,
          :m,
          [:args, :a, [:kwargs, [:a], [[:lasgn, :a, [:lit, 1]]]]],
          [:scope, [:block, [:lvar, :a]]]]]]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a: 1, b: 2) end
    ruby

    [:defn,
     :m,
     [:args,
      :a,
      :b,
      [:kwargs, [:a, :b], [[:lasgn, :a, [:lit, 1]], [:lasgn, :b, [:lit, 2]]]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a: 1, **) end
    ruby

    [:defn,
     :m,
     [:args, :a, :**, [:kwargs, [:a, :**], [[:lasgn, :a, [:lit, 1]]]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a: 1, **k) end
    ruby

    [:defn,
     :m,
     [:args, :a, :"**k", [:kwargs, [:a, :"**k"], [[:lasgn, :a, [:lit, 1]]]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a: 1, &b) end
    ruby

    [:defn,
     :m,
     [:args, :a, :"&b", [:kwargs, [:a], [[:lasgn, :a, [:lit, 1]]]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(**, &b) end
    ruby

    [:defn, :m, [:args, :**, :"&b", [:kwargs, [:**]]], [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(**k, &b) end
    ruby

    [:defn,
     :m,
     [:args, :"**k", :"&b", [:kwargs, [:"**k"]]],
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m(a, b=1, *c, d, e:, f: 2, g:, **k, &l) end
    ruby

    [:defn,
     :m,
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
     [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      def m a, b=1, *c, d, e:, f: 2, g:, **k, &l
      end
    ruby

    [:defn,
     :m,
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
     [:scope, [:block, [:nil]]]]
  end
end
