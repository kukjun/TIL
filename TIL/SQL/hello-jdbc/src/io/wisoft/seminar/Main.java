package io.wisoft.seminar;

public class Main {
    public static void main(String[] args) {

        // SELECT AREA
        StudentSelectService selectStudent = new StudentSelectService();

        System.out.println("전체 학생을 검색합니다.");
        selectStudent.getStudentAll();
        System.out.println("");
    }
}
//        Student student = new Student();
//        Student[] students = new Student[8];
//
//        for (int i=0; i<students.length; i++){
//            students[i] = new Student();
//        }
//
//        // INSERT AREA
//        StudentlnsertService studentlnsert = new StudentlnsertService();
//
//        System.out.println("학번이 20110901이고, 이름이 이상훈인 학생을 추가합니다.");
//        System.out.println("학번이 20110901이고, 이름이 강동희인 학생을 추가합니다.");
//        System.out.println("학번이 20110901이고, 이름이 이상훈인 학생을 추가합니다.");
//        System.out.println("학번이 20110901이고, 이름이 이상훈인 학생을 추가합니다.");
//        student.setStudentNo("20110401");
//        student.setStudentName("이순신");
//        insertStudent.insertStudent(student);
//
//        student.getStudentNo();
//        System.out.println("");
//    }
//}