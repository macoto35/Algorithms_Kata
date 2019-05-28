package hackerRank.daysOfCode;

import java.util.*;

/*
- Error: Created by System level. No need to handle.
- Exception: Created by program logic. Need to handle.

[Structure of Exception Class]
              Object
             Throwable
    Error                 Exception
             Checked Exception     RuntimeException
                                   Unchecked Exception

- Checked Exception: Need to handle / check in compile / no rollback / all exceptions except Runtime Exception(IOException, SQLException...)
- UnChecked Exception: Not forced to handle / check in runtime / rollback / all Runtime Exceptions (NullPointException, IndexOutOfBoundException, IllegalArgumentException...)

- How to handle Exception?
1. Recover: keep running the process. (e.g. connect DB)
int maxRetry = MAX_RETRY;
while (maxRetry-- > 0) {
  try {
      // connect DB
      return;
  } catch (SomeException ex) {
      print log and wait 5s
  } finally {
      close connection and tear down process
  }
}
throw new RetryFailedException();

2. Propagate: just throw exception. (using throws)
public void add() throws SQLException {...}

3. Switch: catch exception and rephrasing it
catch (SQLException e) {
...
throw DuplicateUserIdException();
}
*/
public class Day16 {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in);){
            String s = scanner.nextLine();
            System.out.println(Integer.parseInt(s));
        } catch (NumberFormatException nfe) {
            System.out.println("Bad String");
        }
    }
}
