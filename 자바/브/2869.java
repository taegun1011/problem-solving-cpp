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

		StringTokenizer st = new StringTokenizer(br.readLine());
		int a, b, v;
		a = Integer.parseInt(st.nextToken());
		b = Integer.parseInt(st.nextToken());
		v = Integer.parseInt(st.nextToken());

		// k번째 낮에 도달할 수 있는 거리 : (k - 1)(a - b) + a
		int d = (v - a) / (a - b) + 1;
		d += ((v - a) % (a - b) == 0) ? 0 : 1;

		sb.append(d);
		System.out.println(sb);
		br.close();
	}
}