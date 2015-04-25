public class Broken {
	private final int dataSize = (int) (Runtime.getRuntime().maxMemory() * 0.5);

	public void f() {
		{
			byte[] data = new byte[dataSize];
		}

		byte[] data2 = new byte[dataSize];
	}

	public static void main(String[] args) {
		Broken jmp = new Broken();
		jmp.f();
	}
}
