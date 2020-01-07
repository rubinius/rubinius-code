describe "A Call node using kernel_methods transform" do
  relates "a.class" do
    compile do |g|
      g.push :self
      g.send :a, 0, true
      g.send :class, 0, false
    end

    compile :kernel_methods do |g|
      g.push :self
      g.send :a, 0, true
      g.send :__class__, 0, false
    end
  end
end
