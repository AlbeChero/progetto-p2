ifndef NEGOZIO_H
#define NEGOZIO_H

#include <QPushButton>
#include <QScrollBar>
#include <QVBoxLayout>
#include <QCheckBox>

class layoutNegozio : public QWidget{
private:
    QWidget* parent;
    QPushButton *bottoneAggiungi;
    QPushButton *bottoneRimuovi;
    QPushButton *bottoneModifica;
    QCheckBox *checkbox1;
    QCheckBox *checkbox2;
    QCheckBox *checkbox3;
    QCheckBox *checkbox4;

public:

    layoutNegozio(QWidget* =nullptr);
    ~layoutNegozio();
    QPushButton *getBtnAggiungi() const;
    QPushButton *getBtnRimuovi() const;
    QPushButton *getBtnModifica() const;
    QCheckBox *getCheckBox1() const;
    QCheckBox *getCheckBox2() const;
    QCheckBox *getCheckBox3() const;
    QCheckBox *getCheckBox4() const;

};

#endif // NEGOZIO_H
