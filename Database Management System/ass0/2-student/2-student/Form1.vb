
Public Class Form1
    Inherits Main

    Private Sub add_form_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        Me.Text = "Welcome!"
    End Sub
    Private Sub addButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles addButton.Click
        Add.Show()
    End Sub

    Private Sub searchButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles searchButton.Click
        Search.Show()
    End Sub

    Private Sub editButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles editButton.Click
        Edit.Show()
    End Sub

    Private Sub deleteButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles deleteButton.Click
        Delete.Show()
    End Sub

    Private Sub displayButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles displayButton.Click
        Display.Show()
    End Sub
End Class
