Public Class Main
    Public Structure student
        Dim roll As String
        Dim dcode As String
        Dim name As String
        Dim address As String
        Dim phone As Integer
        Dim isDeleted As Integer
    End Structure
    Public Structure department
        Dim dcode As String
        Dim name As String
        Dim totalstudents As Integer
    End Structure
    Public Shared arrStu(4, 50) As student
    Public Shared arrDept(4) As department
    Public Sub yo()
        arrStu(0, 0).roll = 12
        arrStu(0, 0).dcode = "cse"
        arrStu(0, 0).address = "ju main"
        arrStu(0, 0).phone = 987653212

        For count = 0 To 15
            Console.WriteLine("Array element: " & count & arrStu(0, count).name & arrStu(0, count).dcode)
        Next count
    End Sub
    Private Sub Main_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        'yo()
        arrDept(0).name = "CIVIL"
        arrDept(0).dcode = "BCIV"
        arrDept(1).name = "CSE"
        arrDept(1).dcode = "BCSE"
        arrDept(2).name = "ETCE"
        arrDept(2).dcode = "BETC"
        arrDept(3).name = "MECH"
        arrDept(3).dcode = "BMEC"

    End Sub
End Class
