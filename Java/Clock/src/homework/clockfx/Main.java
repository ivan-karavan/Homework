package homework.clockfx;

import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.util.Duration;

public class Main extends Application {
    @Override
    public void start(Stage primaryStage) throws Exception {

        FXMLLoader loader = new FXMLLoader(getClass().getResource("sample.fxml"));
        Parent root = (Parent) loader.load();
        final Controller controller = loader.getController();
        Scene sc = new Scene(root, 300, 300);

        Timeline timeline = new Timeline(new KeyFrame(new Duration(1000), new javafx.event.EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                if (controller.isRunning()) {
                    controller.updateTime();
                    controller.paint();
                }
            }
        }));

        timeline.setCycleCount(Timeline.INDEFINITE);
        controller.setRunning(true);
        timeline.play();

        primaryStage.setScene(sc);
        primaryStage.show();
    }


    public static void main(String[] args) {
        launch(args);
    }
}
