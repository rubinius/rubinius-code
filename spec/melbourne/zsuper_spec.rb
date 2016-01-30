describe "A Zsuper node" do
  parse <<-ruby do
      def x
        super
      end
    ruby

    [:defn, :x, [:args], [:scope, [:block, [:zsuper]]]]
  end

  parse <<-ruby do
      def x(a)
        super
      end
    ruby

    [:defn, :x, [:args, :a], [:scope, [:block, [:zsuper]]]]
  end

  parse <<-ruby do
      def x(&block)
        super
      end
    ruby

    [:defn, :x, [:args, :"&block"], [:scope, [:block, [:zsuper]]]]
  end

  parse <<-ruby do
      def x(a, *as)
        super
      end
    ruby

    [:defn, :x, [:args, :a, :"*as"], [:scope, [:block, [:zsuper]]]]
  end
end
