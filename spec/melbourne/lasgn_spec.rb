describe "An Lasgn node" do
  parse "a = 1" do
    [:lasgn, :a, [:lit, 1]]
  end

  parse "a = b, c, *d" do
    [:lasgn,
     :a,
     [:argscat,
      [:array, [:call, nil, :b, [:arglist]], [:call, nil, :c, [:arglist]]],
      [:call, nil, :d, [:arglist]]]]
  end

  parse "a = [b, *c]" do
    [:lasgn,
     :a,
     [:argscat,
      [:array, [:call, nil, :b, [:arglist]]],
      [:call, nil, :c, [:arglist]]]]
  end

  parse <<-ruby do
      x = (y = 1
           (y + 2))
    ruby

    [:lasgn,
       :x,
       [:block,
        [:lasgn, :y, [:lit, 1]],
        [:call, [:lvar, :y], :+, [:arglist, [:lit, 2]]]]]
  end

  parse <<-ruby do
      a = []
      a [42]
    ruby

    [:block,
     [:lasgn, :a, [:array]],
     [:call, [:lvar, :a], :[], [:arglist, [:lit, 42]]]]
  end

  parse 'var = ["foo", "bar"]' do
    [:lasgn, :var, [:array, [:str, "foo"], [:str, "bar"]]]
  end

  parse "c = (2 + 3)" do
    [:lasgn, :c, [:call, [:lit, 2], :+, [:arglist, [:lit, 3]]]]
  end

  parse "a = *[1]" do
    [:lasgn, :a, [:splat, [:array, [:lit, 1]]]]
  end

  parse "a = *b" do
    [:lasgn, :a, [:splat, [:call, nil, :b, [:arglist]]]]
  end

  parse <<-ruby do
      a = if c
            begin
              b
            rescue
              nil
            end
          end
      a
    ruby

    [:block,
     [:lasgn,
      :a,
      [:if,
       [:call, nil, :c, [:arglist]],
       [:rescue,
        [:call, nil, :b, [:arglist]],
        [:resbody, [:array, [:const, :StandardError]], [:nil]]],
       nil]],
     [:lvar, :a]]
  end

  parse "x = [*[1]]" do
    [:lasgn, :x, [:splat, [:array, [:lit, 1]]]]
  end

  parse "a = []" do
    [:lasgn, :a, [:array]]
  end

  parse <<-ruby do
      a = 12
      a
    ruby

    [:block, [:lasgn, :a, [:lit, 12]], [:lvar, :a]]
  end

  parse <<-ruby do
      name
      name = 3
      name
    ruby

    [:block,
     [:call, nil, :name, [:arglist]],
     [:lasgn, :name, [:lit, 3]],
     [:lvar, :name]]
  end

  parse "a=12; b=13; true" do
    [:block, [:lasgn, :a, [:lit, 12]], [:lasgn, :b, [:lit, 13]], [:true]]
  end

  parse <<-ruby do
      def f
        a = 1
      end
    ruby

    [:defn, :f, [:args], [:scope, [:block, [:lasgn, :a, [:lit, 1]]]]]
  end

  parse <<-ruby do
      def f(a)
        a = 1
      end
    ruby

    [:defn, :f, [:args, :a], [:scope, [:block, [:lasgn, :a, [:lit, 1]]]]]
  end

  parse <<-ruby do
      def f
        b { a = 1 }
      end
    ruby

    [:defn,
     :f,
     [:args],
     [:scope,
      [:block,
       [:call, nil, :b, [:arglist, [:iter, [:args], [:lasgn, :a, [:lit, 1]]]]]]]]
  end

  parse <<-ruby do
      def f(a)
        b { a = 2 }
      end
    ruby

    [:defn,
     :f,
     [:args, :a],
     [:scope,
      [:block,
       [:call, nil, :b, [:arglist, [:iter, [:args], [:lasgn, :a, [:lit, 2]]]]]]]]
  end

  parse <<-ruby do
      def f
        a = 1
        b { a = 2 }
      end
    ruby

    [:defn,
     :f,
     [:args],
     [:scope,
      [:block,
       [:lasgn, :a, [:lit, 1]],
       [:call, nil, :b, [:arglist, [:iter, [:args], [:lasgn, :a, [:lit, 2]]]]]]]]
  end

  parse <<-ruby do
      def f
        a
        b { a = 1 }
      end
    ruby

    [:defn,
     :f,
     [:args],
     [:scope,
      [:block,
       [:call, nil, :a, [:arglist]],
       [:call, nil, :b, [:arglist, [:iter, [:args], [:lasgn, :a, [:lit, 1]]]]]]]]
  end

  parse <<-ruby do
      def f
        b { a = 1 }
        a
      end
    ruby

    [:defn,
     :f,
     [:args],
     [:scope,
      [:block,
       [:call, nil, :b, [:arglist, [:iter, [:args], [:lasgn, :a, [:lit, 1]]]]],
       [:call, nil, :a, [:arglist]]]]]
  end

  parse <<-ruby do
      def f
        a = 1
        b { a = 2 }
        a
      end
    ruby

    [:defn,
     :f,
     [:args],
     [:scope,
      [:block,
       [:lasgn, :a, [:lit, 1]],
       [:call, nil, :b, [:arglist, [:iter, [:args], [:lasgn, :a, [:lit, 2]]]]],
       [:lvar, :a]]]]
  end

  parse <<-ruby do
      class F
        a = 1
      end
    ruby

    [:class, :F, nil, [:scope, [:block, [:lasgn, :a, [:lit, 1]]]]]
  end

  parse <<-ruby do
      a = Object
      class a::F
        b = 1
      end
    ruby

    [:block,
     [:lasgn, :a, [:const, :Object]],
     [:class,
      [:colon2, [:lvar, :a], :F],
      nil,
      [:scope, [:block, [:lasgn, :b, [:lit, 1]]]]]]
  end

  parse <<-ruby do
      a = Object
      class F < a
        b = 1
      end
    ruby

    [:block,
     [:lasgn, :a, [:const, :Object]],
     [:class, :F, [:lvar, :a], [:scope, [:block, [:lasgn, :b, [:lit, 1]]]]]]
  end

  parse <<-ruby do
      class F
        a = 1
        def f
          a = 1
        end
      end
    ruby

    [:class,
     :F,
     nil,
     [:scope,
      [:block,
       [:lasgn, :a, [:lit, 1]],
       [:defn, :f, [:args], [:scope, [:block, [:lasgn, :a, [:lit, 1]]]]]]]]
  end

  parse <<-ruby do
      module M
        a = 1
      end
    ruby

    [:module, :M, [:scope, [:block, [:lasgn, :a, [:lit, 1]]]]]
  end

  parse <<-ruby do
      module M
        a = 1
        def f
          a = 1
        end
      end
    ruby

    [:module,
     :M,
     [:scope,
      [:block,
       [:lasgn, :a, [:lit, 1]],
       [:defn, :f, [:args], [:scope, [:block, [:lasgn, :a, [:lit, 1]]]]]]]]
  end

  parse <<-ruby do
      a = Object
      module a::M
        b = 1
      end
    ruby

    [:block,
     [:lasgn, :a, [:const, :Object]],
     [:module,
      [:colon2, [:lvar, :a], :M],
      [:scope, [:block, [:lasgn, :b, [:lit, 1]]]]]]
  end
end
