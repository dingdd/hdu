public class Fixed {
	private final int dataSize = (int) (Runtime.getRuntime().maxMemory() * 0.5);

	public void f() {
		{
			 byte[] data = new byte[dataSize];
		}

		for(int i=0; i < 10; ++i) {
			System.out.println("Please release the memory, Java");
		}
		byte[] data2 = new byte[dataSize];
	}

	public static void main(String[] args) {
		Fixed jmp = new Fixed();
		jmp.f();
	}
}
