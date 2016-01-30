describe "A Defs node" do
  parse <<-ruby do
      def self.m() end
    ruby

    [:defs, [:self], :m, [:args], [:scope, [:block, [:nil]]]]
  end

  parse <<-ruby do
      a = ""
      def a.m() end
    ruby

    [:block,
     [:lasgn, :a, [:str, ""]],
     [:defs, [:lvar, :a], :m, [:args], [:scope, [:block, [:nil]]]]]
  end

  parse <<-ruby do
      a = ""
      def (a.b).m() end
    ruby

    [:block,
     [:lasgn, :a, [:str, ""]],
     [:defs,
      [:call, [:lvar, :a], :b, [:arglist]],
      :m,
      [:args],
      [:scope, [:block, [:nil]]]]]
  end

  parse <<-ruby do
      def x.m(a=1, (b, (c, *d), *e)) end
    ruby

    [:defs,
     [:call, nil, :x, [:arglist]],
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
      def x.m(a, b=1, *c, d, e:, f: 2, g:, **k, &l) end
    ruby

    [:defs,
     [:call, nil, :x, [:arglist]],
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
      def x.m a, b=1, *c, d, e:, f: 2, g:, **k, &l
      end
    ruby

    [:defs,
     [:call, nil, :x, [:arglist]],
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
