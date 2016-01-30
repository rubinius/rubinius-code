describe "An Sclass node" do
  parse <<-ruby do
      class << self
        42
      end
    ruby

    [:sclass, [:self], [:scope, [:block, [:lit, 42]]]]
  end

  parse <<-ruby do
      class A
        class << self
          a
        end
        class B
        end
      end
    ruby

    [:class,
     :A,
     nil,
     [:scope,
      [:block,
       [:sclass, [:self], [:scope, [:block, [:call, nil, :a, [:arglist]]]]],
       [:class, :B, nil, [:scope]]]]]
  end

  parse <<-ruby do
      x = "a"
      class << x
      end
    ruby

    [:block,
      [:lasgn, :x, [:str, "a"]],
      [:sclass, [:lvar, :x], [:scope]]]
  end

  parse <<-ruby do
      x = "a"
      m do
        class << x
        end
      end
    ruby

    [:block,
     [:lasgn, :x, [:str, "a"]],
     [:call,
      nil,
      :m,
      [:arglist, [:iter, [:args], [:sclass, [:lvar, :x], [:scope]]]]]]
  end
end
