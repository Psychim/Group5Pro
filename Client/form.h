#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
    class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    void initEmotion();
    ~Form();

private:
    Ui::Form *ui;
private slots:
    void addEmotionItem(QString);
};

#endif // FORM_H
