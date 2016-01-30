describe "A Module node" do
  parse <<-ruby do
      module X
        def y
        end
      end
    ruby

    [:module,
    :X,
    [:scope, [:block, [:defn, :y, [:args], [:scope, [:block, [:nil]]]]]]]
  end

  parse <<-ruby do
      module ::Y
        c
      end
    ruby

    [:module, [:colon3, :Y], [:scope, [:block, [:call, nil, :c, [:arglist]]]]]
  end

  parse <<-ruby do
      module X::Y
        c
      end
    ruby

    [:module,
     [:colon2, [:const, :X], :Y],
     [:scope, [:block, [:call, nil, :c, [:arglist]]]]]
  end

  parse <<-ruby do
      "prevent the above from infecting rdoc"

      module Graffle
      end
    ruby

    [:module, :Graffle, [:scope]]
  end
end
