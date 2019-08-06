package blog.recursive;

import javax.swing.*;
import java.awt.*;
import java.awt.geom.GeneralPath;
import java.util.concurrent.TimeUnit;

public class DrawFractal {
	private JFrame frame;
	private JPanel panel;

	public DrawFractal() {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				createAndShowGUI();
			}
		});
	}

	private void createAndShowGUI() {
		frame = new JFrame("Draw Fractal");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		panel = new MyPanel();
		frame.add(panel);
		frame.pack();
		frame.setVisible(true);
	}

	class MyPanel extends JPanel {
		public MyPanel() {
			setBorder(BorderFactory.createLineBorder(Color.black));
		}

		@Override
		public Dimension getPreferredSize() {
			return new Dimension(500, 500);
		}
	}

	private void drawTriangle(double x, double y, double w, double h) {
		Graphics2D g = (Graphics2D) panel.getGraphics();

		double xp[] = {x, x+w, x+w/2, x};
		double yp[] = {y, y, y-h, y};

		GeneralPath polyline = new GeneralPath(GeneralPath.WIND_EVEN_ODD, 4);
		polyline.moveTo(xp[0], yp[0]);

		for (int i = 1; i < 4; i++)
			polyline.lineTo(xp[i], yp[i]);

		g.draw(polyline);
	}

	public void draw(double x, double y, double w, double h) {
		drawTriangle(x, y, w, h);
		
		if (w < .2 || h < .2)
			return;

		double halfW = w / 2;
		double halfH = h / 2;

		/*
			drawing order will be changed based on this
		*/
		draw(x, y, halfW, halfH); // left
		draw(x + halfW/2, y - halfH, halfW, halfH); // top
		draw(x + halfW, y, halfW, halfH); // right
	}

	public static void main(String[] args) {
		try {
			DrawFractal df = new DrawFractal();

			while (df.panel == null)
				TimeUnit.SECONDS.sleep(1);

			df.draw(0, 400, 400, 400);
		} catch (Exception ex) {
			ex.printStackTrace();
		}
	}
}
