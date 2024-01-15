//이 줄 지우기
package ps;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());

		StringBuilder sb = new StringBuilder();
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < i; j++)
				sb.append('*');
			sb.append('\n');
		}
		System.out.println(sb);
		br.close();
	}
}