describe "A Super node" do
  parse <<-ruby do
      def x
        super()
      end
    ruby

    [:defn, :x, [:args], [:scope, [:block, [:super]]]]
  end

  parse <<-ruby do
      def x(&block)
        super(&block)
      end
    ruby

    [:defn,
     :x,
     [:args, :"&block"],
     [:scope, [:block, [:super, [:block_pass, [:lvar, :block]]]]]]
  end

  parse <<-ruby do
      def x
        super([24, 42])
      end
    ruby

    [:defn,
     :x,
     [:args],
     [:scope, [:block, [:super, [:array, [:lit, 24], [:lit, 42]]]]]]
  end

  parse <<-ruby do
      def x
        super(4)
      end
    ruby

    [:defn, :x, [:args], [:scope, [:block, [:super, [:lit, 4]]]]]
  end

  parse "super(a, &b)" do
    [:super,
     [:call, nil, :a, [:arglist]],
     [:block_pass, [:call, nil, :b, [:arglist]]]]
  end

  parse "super(a, *b)" do
    [:super,
      [:call, nil, :a, [:arglist]],
      [:splat, [:call, nil, :b, [:arglist]]]]
  end

  parse <<-ruby do
      def x
        super(24, 42)
      end
    ruby

    [:defn,
      :x,
      [:args],
      [:scope, [:block, [:super, [:lit, 24], [:lit, 42]]]]]
  end

  parse "super([*[1]])" do
    [:super, [:splat, [:array, [:lit, 1]]]]
  end

  parse "super(*[1])" do
    [:super, [:splat, [:array, [:lit, 1]]]]
  end
end
