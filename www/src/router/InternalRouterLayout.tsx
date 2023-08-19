type Props = {
  children: React.ReactNode;
};

export function InternalRouterLayout({ children }: Props) {
  return <div>{children}</div>;
}
