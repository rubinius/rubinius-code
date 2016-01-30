describe "A Cvasgn node" do
  parse <<-ruby do
      def x
        @@blah = 1
      end
    ruby

    [:defn,
     :x,
     [:args],
     [:scope, [:block, [:cvasgn, :@@blah, [:lit, 1]]]]]
  end

  parse <<-ruby do
      def self.quiet_mode=(boolean)
        @@quiet_mode = boolean
      end
    ruby

    [:defs,
     [:self],
     :quiet_mode=,
     [:args, :boolean],
     [:scope, [:block, [:cvasgn, :@@quiet_mode, [:lvar, :boolean]]]]]
  end

  parse <<-ruby do
      class X
        @@blah = 1
      end
    ruby

    [:class, :X, nil, [:scope, [:block, [:cvasgn, :@@blah, [:lit, 1]]]]]
  end
end
