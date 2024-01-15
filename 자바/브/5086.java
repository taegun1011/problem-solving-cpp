//이 줄 지우기
package ps;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringBuilder sb = new StringBuilder();
		int a = 0, b = 0;
		while (true) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			if (a == 0 && b == 0)
				break;

			if (a % b == 0) {
				sb.append("multiple\n");
			} else if (b % a == 0) {
				sb.append("factor\n");
			} else {
				sb.append("neither\n");
			}

		}
		System.out.println(sb);
		br.close();
	}
}