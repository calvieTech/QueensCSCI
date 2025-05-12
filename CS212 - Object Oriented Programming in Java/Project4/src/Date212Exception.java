// Calvin Thang
// 11A

// custom exception class extends from IllegalArgumentException
public class Date212Exception extends IllegalArgumentException {
   // non-default constructor
   public Date212Exception(String message) {
      // call message function from super class
      super(message);
   }
}