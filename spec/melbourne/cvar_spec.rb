describe "A Cvar node" do
  parse "@@x" do
    [:cvar, :@@x]
  end

  parse <<-ruby do
      class A
        @@a
      end
    ruby

    [:class, :A, nil, [:scope, [:block, [:cvar, :@@a]]]]
  end

  parse <<-ruby do
      module M
        @@a
      end
    ruby

    [:module, :M, [:scope, [:block, [:cvar, :@@a]]]]
  end
end
