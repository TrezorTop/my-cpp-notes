#include <iostream>
#include <string>

using std::cout, std::string;

class Point {
  public:
  private:
};

template <typename T>
class TemplateClass {
  public:
    explicit TemplateClass() {}

    void SizeOf() {
      cout << sizeof(this->value) << '\n';
    }

    T GetValue() {
      return this->value;
    }

  protected:
    T value;
};

template <typename T>
class InheritedTemplateClass : public TemplateClass<T> {
  public:
    explicit InheritedTemplateClass(T value) : TemplateClass<T>() {}

    void PrintTypeName() {
      cout << "Type name: " << typeid(this->value).name() << '\n';
    }

  private:
};

int main() {
  Point point;

  InheritedTemplateClass templateExample(point);

  templateExample.PrintTypeName();
  templateExample.SizeOf();
  return 0;
}
