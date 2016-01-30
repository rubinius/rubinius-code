describe "An Alias node" do
  parse <<-ruby do
      class X
        alias :y :x
      end
    ruby

    [:class, :X, nil, [:scope, [:block, [:alias, [:lit, :y], [:lit, :x]]]]]
  end

  parse <<-ruby do
      class X
        alias y x
      end
    ruby

    [:class, :X, nil, [:scope, [:block, [:alias, [:lit, :y], [:lit, :x]]]]]
  end

  parse <<-ruby do
      class X
        alias :"y\#{1}" :"x\#{2}"
      end
    ruby

    [:class,
     :X,
     nil,
     [:scope,
      [:block,
       [:alias,
        [:dsym, "y", [:evstr, [:lit, 1]]],
        [:dsym, "x", [:evstr, [:lit, 2]]]]]]]
  end
end
