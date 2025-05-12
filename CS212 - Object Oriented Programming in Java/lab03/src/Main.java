public class Main {
	public static void main(String args[]) {
		float fahrenheit;
		float centigrade;
		fahrenheit = (float) 98.6;
		centigrade = convertToCentigrade(fahrenheit);
		
		System.out.println("Fahrenheit to Centigrade");
		for (float i = 0; i <= 40; i += 5) {
			System.out.println(convertToCentigrade(i));
		}
		
		float x = 0;
		while (x <= 40) {
			System.out.println(convertToCentigrade(x));
			x += 5;
		}
		
		System.out.println("Centigrade to Fahrenheit");
		for (float i = 0; i <= 40; i += 5) {
			System.out.println(convertToFahrenheit(i));
		}
		
		float y = 0;
		while (y <= 40) {
			System.out.println(convertToFahrenheit(y));
			y += 5;
		}
		
		
		
		
		
	}
	public static float convertToCentigrade(float input) {
		return (float) 5 / 9 * (input - 32);
	}
	
	public static float convertToFahrenheit(float input) {
		return input * (float) 9 / 5 + 32
	}
	
	
	
}