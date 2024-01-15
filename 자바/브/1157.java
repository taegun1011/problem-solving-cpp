//이 줄 지우기
package ps;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine().toUpperCase();
		int[] cArr = new int[26];

		int maxCnt = 0, max = 0;
		char maxChar = '\0';
		for (int i = 0; i < str.length(); i++) {
			int cur = ++cArr[str.charAt(i) - 65];
			if (cur > max) {
				maxCnt = 0;
				max = cur;
				maxChar = str.charAt(i);
			} else if (cur == max) {
				maxCnt++;
				maxChar = '?';
			}
		}

		StringBuilder sb = new StringBuilder();
		sb.append(maxChar);
		System.out.println(sb);
		br.close();
	}
}