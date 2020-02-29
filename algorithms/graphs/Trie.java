import java.util.*;
import java.io.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(bf.readLine());
        int n = Integer.parseInt(st.nextToken());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        // set for no duplicates of strings
        HashSet<String> set = new HashSet<>();
        Trie trie = new Trie();
        String[] inp = bf.readLine().split(" ");
        for (String name : inp)
            set.add(name);
        for (String name : set)
            trie.insert(name, 0);
        set.clear();
        inp = bf.readLine().split(" ");
        for (String name : inp)
            set.add(name);
        for (String name : set)
            trie.insert(name, 1);

        while (n-- > 0) {
            String comp = bf.readLine();
            pw.println(trie.search(comp));
        }
        bf.close();
        pw.flush();
    }
}

class Trie {
    public class Node {
        Node[] arr;
        int ash;
        int brock;
        // 26 because of a-z alphabet
        public Node() {
            arr = new Node[26];
        }
    }
    Node root = new Node();

    // 0 for ash, 1 for brock
    public void insert(String s, int who) {
        Node cur = root;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (cur.arr[c - 'a'] == null)
                cur.arr[c - 'a'] = new Node();
            cur = cur.arr[c - 'a'];
            if (who == 0)
                cur.ash++;
            else
                cur.brock++;
        }
    }

    public String search(String s) {
        Node cur = root;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (cur.arr[c - 'a'] == null)
                return "neither";
            cur = cur.arr[c - 'a'];
        }
        if (cur.ash == cur.brock)
            return "neither";
        return cur.ash > cur.brock ? "Ash" : "Brock";
    }
}
