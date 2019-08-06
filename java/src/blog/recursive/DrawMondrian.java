package blog.recursive;

import javax.swing.*;
import java.awt.*;
import java.util.Random;
import java.util.concurrent.TimeUnit;

public class DrawMondrian {
    JFrame frame;
    JPanel panel;
    Boolean init = true;

    public DrawMondrian() {
        SwingUtilities.invokeLater(new Runnable() {
           @Override
            public void run() {
               createAndShowGUI();
           }
        });
    }

    private void createAndShowGUI() {
        this.frame = new JFrame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.panel = new MyPanel();
        frame.add(panel);
        frame.pack();
        frame.setVisible(true);
    }

    private class MyPanel extends JPanel {
        public MyPanel() {
            setBorder(BorderFactory.createLineBorder(Color.black));
        }

        @Override
        public Dimension getPreferredSize() {
            return new Dimension(400, 400);
        }
    }

    private Color getRandomColor() {
        switch(new Random().nextInt(4)) {
            case 0:
                return Color.red;
            case 1:
                return Color.yellow;
            case 2:
                return Color.blue;
            default:
                return Color.black;
        }
    }

    private void fill(int x, int y, int w, int h) {
        if (!this.init) {
            Graphics g = this.panel.getGraphics();
            Random rand = new Random();

            switch(rand.nextInt(2)) {
                case 0:
                    g.setColor(Color.white);
                    break;
                case 1:
                    g.setColor(this.getRandomColor());
                    break;
            }

            g.fillRect(x+1, y+1, w-1, h-1);
        }
    }

    private void drawLine(int x, int y, int w, int h) {
        Graphics g = this.panel.getGraphics();
        g.setColor(Color.black);
        g.drawRect(x, y, w, h);
    }

    public void draw(int x, int y, int w, int h) {
        if (w < 100 || h < 100)
            return;

        // System.out.println(x + "/" + y + "/" + w + "/" + h);
        fill(x, y, w, h);

        int bound = 3;
        if (this.init) {
            bound = 2;
            this.init = false;
        }

        switch(new Random().nextInt(bound)) {
            case 0:
                // vertical line
                // System.out.println("vertical");
                int randW = new Random().nextInt(w) + 1;
                drawLine(x, y, randW, h);
                draw(x, y, randW, h);
                draw(x + randW, y, w - randW, h);
                break;
            case 1:
                // horizontal ilne
                // System.out.println("horizontal");
                int randH = new Random().nextInt(h) + 1;
                drawLine(x, y, w, randH);
                draw(x, y, w, randH);
                draw(x, y + randH, w, h - randH);
                break;
            case 2:
                // System.out.println("do nothing");
                break;
        }
    }

    public static void main(String[] args) {
        try {
            DrawMondrian dm = new DrawMondrian();

            while (dm.panel == null)
                TimeUnit.SECONDS.sleep(1);

            dm.draw(0, 0, 400, 400);
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}
