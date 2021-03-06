FancySpec describe: Stack with: {
  it: "should be empty when created" for: '<< when: {
    s = Stack new
    s empty? should == true
  }

  it: "should return the last inserted element" for: 'pop when: {
    s = Stack new
    s push: 1
    s pop should == 1

    objs = [1,2,3]
    objs each: |x| {
      s push: x
    }

    objs reverse each: |x| {
      s pop should == x
    }

  }
}
